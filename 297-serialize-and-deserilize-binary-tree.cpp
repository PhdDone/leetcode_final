/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
*/

/* LinkedIn */

// pre order traversal
//string to int
//http://www.cplusplus.com/reference/string/stoi/

//split string
//http://stackoverflow.com/questions/236129/split-a-string-in-c

//join string

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
#include <sstream>
#include <iterator>
 
class Codec {
public:
    
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    vector<string> output;
    serialize(root, output);
    string delim = " ";
    ostringstream imploded;  //join vector strings to string 
    copy(output.begin(), output.end(), ostream_iterator<string>(imploded, delim.c_str()));
    return imploded.str(); //ostringstream to string
  }
    
  void serialize(TreeNode* node, vector<string>& output) {
    if (node == nullptr) {
      output.push_back("#");
      return;
    }
    string val(to_string(node->val));
    output.push_back(val);
    serialize(node->left, output);
    serialize(node->right, output);
  }
  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    int index = 0;
    vector<string> tokens;
    istringstream iss(data);
    copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens));
    return deserialize(tokens, index);
  }
    
  TreeNode* deserialize(const vector<string>& data, int& index) { //index use references
    if (index >= data.size() || data[index] == "#") {
      return nullptr;
    }
    TreeNode* node = new TreeNode(stoi(data[index])); //string to int
    index++;
    node->left = deserialize(data, index);
    index++;
    node->right = deserialize(data, index);
    return node;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
