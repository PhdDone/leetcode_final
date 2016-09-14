//http://blog.csdn.net/xudli/article/details/45840001

#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class TireNode {
public:
  unordered_map<char, TireNode*> children;
  char c;
  // mark the leaf!!!
  bool isLeaf = false;
  
  TireNode() {}
  TireNode (char x) : c(x) {}
  ~TireNode() {
    for (auto& child : children) {
      delete child.second;
    }
  }
};

class WordDictionary {
public:

  // Adds a word into the data structure.
  void addWord(string word) {
    auto children = root->children;
    children['b'] = new TireNode();
    for (char c : word) {
      auto iter = children.find(c);
      if (iter == children.end()) {
        children[c] = new TireNode(c);
        children = children[c]->children;
      } else {
        children = iter->second->children;
      }
    }
  }

  // Returns if the word is in the data structure. A word could
  // contain the dot character '.' to represent any one letter.
  bool search(string word) {
    return search(word, root);
  }
  bool search(string word, TireNode* root) {
    auto children = root->children;
    for (int i = 0; i < word.size(); ++i) {
      char c = word[i];
      auto iter = children.find(c);
      if (iter == children.end()) {
        if (c == '.') {
          for (auto child : children)
            if (search(word.substr(i+1), child.second)) return true;
        } else {
          return false;
        }
      } else {
        children = iter->second->children;
      }
    }
    return true;
  }

  TireNode* root = new TireNode();
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main() {
  WordDictionary wordDictionary;
  wordDictionary.addWord("a");
  cout << wordDictionary.search("a");
  return 0;
}
