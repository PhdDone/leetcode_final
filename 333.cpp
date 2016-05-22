
public class Solution {
    public class SuperNode {
      int ans;
      int small, large;
      boolean isBST;
		   public SuperNode() {
		     ans = 0;
		     isBST = true;
		     small = Integer.MAX_VALUE;
		     large = -Integer.MAX_VALUE;
		   }
    }
    public int largestBSTSubtree(TreeNode root) {
      return dfs(root).ans;
    }
    public SuperNode dfs(TreeNode node) {
      if (node == null) {
	return new SuperNode();
      }
      SuperNode now = new SuperNode(); //auto now = make_shared<SuperNode>()
      SuperNode left = dfs(node.left);
      SuperNode right = dfs(node.right);
      if (left.small < node.val) {
	now.small = left.small;
      } else {
	now.small = node.val;
      }
      now.large = Math.max(right.large,node.val);
      if (left.isBST && right.isBST && left.large <= node.val && right.small >= node.val) {
	now.ans = left.ans + right.ans +1;
	now.isBST = true;
      } else {
	now.ans=Math.max(left.ans,right.ans);
	now.isBST = false;
      }
      return now;
    }
}

//solution 2
class Solution {
public:
  int largestBSTSubtree(TreeNode* root) {
    TreeNode *largestBST = NULL;
    int right_min = INT_MAX;
    int left_max = INT_MIN;
    int maxNodes = 0;
    findLargestBSTSubtree(root, right_min, left_max, maxNodes, largestBST);
    return maxNodes;
  }
  // Find the largest BST subtree in a binary tree.                                                                
  // If the subtree is a BST, return total number of nodes.                                                        
  // If the subtree is not a BST, -1 is returned.                                                                  
  int findLargestBSTSubtree(TreeNode *p, int &min, int &max,
                            int &maxNodes, TreeNode *& largestBST) {
    if (!p) return 0;
    bool isBST = true;
    int leftNodes = findLargestBSTSubtree(p->left, min, max, maxNodes, largestBST);
    // currMin and currMax are prepared for the parent of current node
    int currMin = (leftNodes == 0) ? p->val : min;  //!!! Don't mistake the currMin and currMax !!! min is from the left children
    if (leftNodes == -1 || (leftNodes != 0 && p->val <= max))
      isBST = false;
    int rightNodes = findLargestBSTSubtree(p->right, min, max, maxNodes, largestBST);
    int currMax = (rightNodes == 0) ? p->val : max; // max is from right children
    
    if (rightNodes == -1 || (rightNodes != 0 && p->val >= min))
      isBST = false;
    
    if (isBST) {
      min = currMin;
      max = currMax;
      int totalNodes = leftNodes + rightNodes + 1;
      if (totalNodes > maxNodes) {
        maxNodes = totalNodes;
        largestBST = p;
      }
      return totalNodes;
    } else {
      return -1;   // This subtree is not a BST                                                                    
    }
  }
};
