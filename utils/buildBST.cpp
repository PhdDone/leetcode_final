#include "BinaryTree.hpp"

TreeNode* bbt(vector<int> const& values, int start, int end) {
  if (start > end) return nullptr;
  int mid = start + (end - start) / 2;
  TreeNode* cur = new TreeNode(values[mid]);
  cur->left = bbt(values, start, mid - 1);
  cur->right = bbt(values, mid + 1, end);
  return cur;
}

//binary search tree actually
TreeNode* BuildBinaryTree(vector<int> values) {
  auto root = bbt(values, 0, values.size() - 1);
  return root;
}

void deleteTree(TreeNode* root) {
  if (root == nullptr) return;
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}

/**
{1,2,3,4,5,7,9}
      4
     / \
    2   7
   / \ / \
  1  3 5  9

*/
int calculateDistance(TreeNode* root, int a, int b) {
  auto p = findTreeNodeByValue(root, a);
  auto q = findTreeNodeByValue(root, b);
  auto an = lowestCommonAncestor(root, p, q);
  int x = distanceToChild(an, p);
  int y = distanceToChild(an, q);
  return x + y;
}

int main() {
  vector<int> values {2,7,1,4,9,3,5};
  sort(values.begin(), values.end());
  auto root = BuildBinaryTree(values);
  auto res = inOrderTraverse(root);
  printVector(res);
  cout << "Distance: " << calculateDistance(root, 1, 9) << endl;
  
  deleteTree(root);
  return 0;
}
