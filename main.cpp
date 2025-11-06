#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "HuffmanTree.hpp" 

using namespace std;

int main(int argc, char* argv[]) 
{
    if (argc != 3) 
    
    {
        cerr << "Usage: " << argv[0] << " <header_file> <code_file>" << endl;
        return 1;
    }
    
    const std::string input_dir = "input_output/";
    const std::string hdr_file = input_dir + string(argv[1]);
    const std::string code_file = input_dir + string(argv[2]);
    
    ifstream hdr_stream(hdr_file);
    if (!hdr_stream.is_open()) 
    
    {
        cerr << "Error: Cannot open header file: " << hdr_file << endl;
        return 1;
    }
    
    ifstream code_stream(code_file);
    if (!code_stream.is_open()) 
    
    {
        cerr << "Error: Cannot open code file: " << code_file << endl;
        return 1;
    }
 
    // read pair of headers
    vector<pair<string, string>> header_pairs;
    string line;



    while (getline(hdr_stream, line)) 
    
    {
        size_t space_pos = line.find(' ');
        if (space_pos != string::npos) {
            string word = line.substr(0, space_pos);
            string code = line.substr(space_pos + 1);
            header_pairs.push_back({word, code});
        }
    }


    hdr_stream.close();
    
    // build decoder tree
    HuffmanTree decoder;
    if (!decoder.buildFromHeader(header_pairs)) 
    
    {
        cerr << "Error: Failed to build tree from header" << endl;
        return 1;
    }
    

    size_t last_dot = code_file.rfind('.');
    string base_name = code_file.substr(0, last_dot);
    string out_file = base_name + ".tokens_decoded";
    
    ofstream out_stream(out_file);


    if (!out_stream.is_open()) 
    
    {
        cerr << "Error: Cannot create output file: " << out_file << endl;
        return 1;
    }
    

    //decode 
    if (!decoder.decode(code_stream, out_stream)) 
    {
        cerr << "Error: Decoding failed" << endl;
        return 1;
    }
    
    code_stream.close();
    out_stream.close();
    
    cout << "Decoding complete: " << out_file << endl;
    return 0;
}