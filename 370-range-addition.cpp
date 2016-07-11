/*
Assume you have an array of length n initialized with all 0's and are given k update operations.

Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.

Return the modified array after all k operations were executed.
*/
//http://blog.csdn.net/qq508618087/article/details/51864853


class Solution {
public:
  vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    vector<int> res(length, 0);
    for (auto update : updates) {
      int start = update[0];
      int end = update[1];
      int inc = update[2];
      res[start] += inc; //update the start position by +inc
      if (end + 1 < length) res[end + 1] -= inc; //update the first position after the end by -inc, so the curre sum will stop take effect at end + 1;
    }

    int sum = 0; //accumulated sum
    for (int i = 0; i < length; ++i) {
      sum += res[i];
      res[i] = sum;
    }
    return res;
  }
};
