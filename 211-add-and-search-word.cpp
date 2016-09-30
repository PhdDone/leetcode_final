/*Design a data structure that supports the following two operations:

void addWord(word)
  bool search(word)
  search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

  For example:

addWord("bad")
addWord("dad")
  addWord("mad")
  search("pad") -> false
  search("bad") -> true
  search(".ad") -> true
  search("b..") -> true
  Note:
You may assume that all words are consist of lowercase letters a-z.
*/
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

struct TrieNode {
  bool isWord = false;
  vector<TrieNode*> next;
  TrieNode() {
    next = vector<TrieNode*>(26, nullptr);
  }
};

class WordDictionary {
private:
  TrieNode root;
public:

  // Adds a word into the data structure.
  void addWord(string word) {
    int N = word.size();
    TrieNode* cur = &root;
    for (int i = 0; i < N; ++i) {
      if ((cur->next)[word[i] - 'a'] == nullptr) {
        (cur->next)[word[i] - 'a'] = new TrieNode();
        //cout << word[i] - 'a' << endl;
      }
      cur = (cur->next)[word[i] - 'a'];
    }
    cur->isWord = true;
  }

  // Returns if the word is in the data structure. A word could
  // contain the dot character '.' to represent any one letter.
  bool search(string word) {
    TrieNode* cur = &root;
    return search(word, cur, 0);
  }

  bool search(const string& word, TrieNode* cur, int index) { //use index
    //cout << index << endl;
    if (cur == nullptr) return false;
    int N = word.size();
    if (index == N) return cur->isWord; // when stop!!

    for (int i = index; i < N; ++i) {
      if (word[i] == '.') {
        for (int j = 0; j < 26; ++j) {
          if (search(word, (cur->next)[j], index + 1)) // use index + 1, not ++index !!!
            return true;
        }
      } else {
        if ((cur->next)[word[i] - 'a'] == nullptr) return false;
        else {
          return search(word, (cur->next)[word[i] - 'a'], index + 1);
        }
      }
    }
    return false;
  }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
