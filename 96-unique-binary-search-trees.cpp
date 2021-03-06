
/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

//http://fisherlei.blogspot.com/2013/03/leetcode-unique-binary-search-trees.html

class Solution {
public:
  int numTrees(int n) {
    vector<int> count(n + 1, 0);
    count[0] = 1;
    count[1] = 1;
        
    for (int i = 2; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
	count[i] += count[j]*count[i-j-1];
      }
    }
    return count[n];
  }
};

/*
Count[3] = Count[0]*Count[2]  (1为根的情况)
  + Count[1]*Count[1]  (2为根的情况)
  + Count[2]*Count[0]  (3为根的情况)
*/  
//for node i to be the root, the left must be [0, i-1], the right must be [i+1, n]
