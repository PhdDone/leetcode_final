/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  void inorder(TreeNode* root, vector<int>& v) {
    if (!root) return;
    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
  }

  vector<int> closestKValues(TreeNode* root, double target, int k) {
    vector<int> values;
    inorder(root, values);

    double diff = numeric_limits<double>::max();
    int N = values.size();
    int idx = 0;

    for (int i = 0; i < N; ++i) {
      if (abs(values[i] - target) < diff) {
        diff = abs(values[i] - target);
        idx = i;
      }
    }

    int left = idx - 1;
    int right = idx + 1;

    vector<int> res;
    res.push_back(values[idx]);
    for (int i = 0; i < k - 1; ++i) {
      if (left > 0 && right < N) {
        if (abs(values[left] - target) < abs(values[right] - target)) {
          res.push_back(values[left]);
          --left;
        } else {
          res.push_back(values[right]);
          ++right;
        }
      } else {
        if (left < 0) {
          res.push_back(values[right]);
          ++right;
        } else {
          res.push_back(values[left]);
          --left;
        }
      }
    }
    return res;
  }
};


//better solution
class Solution {
public:
  vector<int> closestKValues(TreeNode* root, double target, int k) {
    vector<int> res;
    inorder(root, target, k, res);
    return res;
  }
  void inorder(TreeNode *root, double target, int k, vector<int> &res) {
    if (!root) return;
    inorder(root->left, target, k, res);
    if (res.size() < k) res.push_back(root->val); //not got k number yet
    else if (abs(root->val - target) < abs(res[0] - target)) { //got better res
      res.erase(res.begin()); //remove from the begin
      res.push_back(root->val); //insert to the end
    } else return; //just return because you can only go further from target
    inorder(root->right, target, k, res);
  }
};
