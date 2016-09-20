/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

Show Company Tags
Show Tags
Show Similar Problems
*/


class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    unordered_map<int, bool> visited;
    for (int num : nums) { //put all nums into visited so that we can check later
      visited[num] = false;
    }
    int res = 0;
    for (int num : nums) {
      if (!visited[num]) {
        visited[num] = true;
        int length = 1;
        for (int j = num + 1; visited.find(j) != visited.end(); ++j) { // can't get the bound of j, use visited.find!!
          visited[j] = true;
          ++length;
        }
        for (int j = num - 1; visited.find(j) != visited.end(); --j) {
          visited[j] = true;
          ++length;
        }
        res = length > res? length: res;
      }
    }
    return res;
  }
};
