#include "HuffmanTree.hpp"

HuffmanTree::HuffmanTree() : root_(nullptr) 
{

}

HuffmanTree::~HuffmanTree() 
{
    destroy(root_);
}

void HuffmanTree::destroy(TreeNode* node) 
{
    if (node) 
    {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

bool HuffmanTree::buildFromHeader(const std::vector<std::pair<std::string, std::string>>& pairs) 
{
    // create new node f it doesnt exist
    if (!root_)
    {
        root_ = new TreeNode();
    }
    //for each pair given put it into the treenode
    for (const auto& [word, code] : pairs) 
    {
        
        TreeNode* current = root_;
        
        // navigate/build 
        for (char bit : code) 
        {
            if (bit == '0') 
            {
                // Go/create left
                if (!current->left) 
                {
                    current->left = new TreeNode();
                }
                current = current->left;
            } 
            
            else if (bit == '1') 
            {
                // Go/create right
                
                if (!current->right) 
                {
                    current->right = new TreeNode();
                }

                
                current = current->right;
            } 
            else 
            
            {
                // Invalid bit in code
                return false;
            }
        }
        
        //store word at leaf
        current->word = word;
    }
    
    return true;
}

bool HuffmanTree::decode(std::istream& code_stream, std::ostream& out_stream) 

{
    if (!root_) 
    {
        return false;
    }
    


    TreeNode* current = root_;
    char ch;
    
    while (code_stream.get(ch)) 
    {
        // skip newlines
        
        if (ch == '\n') 
        {
            continue;
        }
        
        // processing
        if (ch == '0') 
        {
            current = current->left;
        } 
        else if (ch == '1') 
        
        {
            current = current->right;
        } 
        
        else 
        
        {
            // skip if invalid character
            continue;  
        }
        
        // did we reach a leaf?
        if (current && current->isLeaf()) 
        {
            // word output
            out_stream << current->word << std::endl;
            // reset it 
            current = root_;
        }
        
    }
    
    // Check if we ended at a non-leaf (incomplete code)
    if (current != root_) 
    {
        std::cerr << "Warning: Code file ended mid-traversal" << std::endl;
        return false;
    }
    
    return true;
}