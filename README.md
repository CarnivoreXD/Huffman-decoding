# Project 4 Huffman Trees Decoding

## Student Information:

Guillermo Rojas<br>
Student ID: 008008657<br>
https://github.com/CarnivoreXD/Huffman-decoding

## Collaboration & Sources:

Used an LLM to find an issue with my code my arguments were at 2 instead of 3 because I needed to take in 2 arguments from the cli.


## Implementation Details:

The main class accepts two cli arguments a .hdr and a encoded .code file. File validation was implemented to ensure both files exist before processing. A binary tree was built to decode using the TreeNode structure where the buildFromHeader() method reds word/code pairs and constructs the tree by traversing the tree. The decode() method reads the code file character by character travering the tree until reaching a leaf then outputs that word and resets to root.


## Testing & Status: 

Successfully compiled with the script. Tested multiple times locally and on blue with no issues all decoded outputs match expected results.
