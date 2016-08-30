#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int v) : val(v) {}
};

vector<int> inOrderTraverse(TreeNode* const& node) {
  if (node == nullptr) return vector<int>{};
  auto left = inOrderTraverse(node->left);
  auto right = inOrderTraverse(node->right);
  vector<int> res;
  res.insert(res.end(), left.begin(), left.end());
  res.push_back(node->val);
  res.insert(res.end(), right.begin(), right.end());
  return res;
}

template<typename Vec>
void printVector(Vec const& V) {
  for (auto& v : V) {
    cout << v <<", ";
  }
  cout << endl;
}

TreeNode* findTreeNodeByValue(TreeNode* root, int value) {
  if (root == nullptr) return nullptr;
  if (root->val == value) return root;
  auto left = findTreeNodeByValue(root->left, value);
  auto right = findTreeNodeByValue(root->right, value);
  return (left == nullptr)? right : left;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (root == nullptr) return root;
  if (root == p || root == q) return root;
  auto left = lowestCommonAncestor(root->left, p, q);
  auto right = lowestCommonAncestor(root->right, p, q);
  if (left && right) {
    return root;
  } else {
    return (left == nullptr)? right : left;
  }
}

int distanceToChild(TreeNode* root, TreeNode* child) {
  if (root == child) return 0;
  if (root == nullptr) return INT_MAX;
  int left = distanceToChild(root->left, child);
  int right = distanceToChild(root->right, child);
  auto res = min(left, right);
  return res + 1;
}
