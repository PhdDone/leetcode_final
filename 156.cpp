#include <stack>
#include <iostream>

/**
 * Definition for a binary tree node.
 struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}

class Solution {
public:
  TreeNode* upsideDownBinaryTree(TreeNode* root) {
    stack<TreeNode*> left;
    stack<TreeNode*> right;
        
    auto cur = root;
        
    while (cur != nullptr) {
      left.push(cur);
      right.push(cur->right);
      cur = cur -> left;
    }
        
    TreeNode* newRoot = nullptr;
    TreeNode* tail = nullptr;
    while (!left.empty()) {
      auto cur = left.top();
      if (newRoot == nullptr) {
	newRoot = cur;
	tail = cur;
	left.pop();
	tail -> left = right.top();
	right.pop();
      }
      else {
	tail->right = cur;
	cur -> left = right.top();
	right.pop();
	left.pop();
	tail = tail->right;
      }
            
    }
    return newRoot;
  }
};


int main() {
  TreeNode* a = new TreeNode(1);
  TreeNode* b = new TreeNode(2);
  TreeNode* c= new TreeNode(3);
  a->left = c;
  a->right = b;

  Solution s;
  s.upsideDownBinaryTree(a);

  delete a;
  delete b;
  delete c;
  return 0;
}
