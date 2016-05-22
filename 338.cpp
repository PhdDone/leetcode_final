/*Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].
*/


//https://oncemore2020.github.io/blog/leetcode-338/
class Solution {
public:
  vector<int> countBits(int num) {
    vector<int> res = vector<int>(num+1,0);
    for(int i=1;i<=num;i++){
      res[i] = res[i >> 1] + (i & 1);
    }
    return res;
  }
};
