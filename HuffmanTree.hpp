#ifndef HUFFMANTREE_HPP
#define HUFFMANTREE_HPP

#include <string>
#include <vector>
#include <iostream>

struct TreeNode 
{
    std::string word;  
    TreeNode* left;
    TreeNode* right;
    
    TreeNode() : left(nullptr), right(nullptr) {}
    TreeNode(const std::string& w) : word(w), left(nullptr), right(nullptr) {}
    
    bool isLeaf() const { return left == nullptr && right == nullptr; }
};

class HuffmanTree 
{
public:
    HuffmanTree();
    ~HuffmanTree();
    
    bool buildFromHeader(const std::vector<std::pair<std::string, std::string>>& pairs);
    bool decode(std::istream& code_stream, std::ostream& out_stream);
    
private:
    TreeNode* root_;
    
    void destroy(TreeNode* node);
};

#endif