/*Oh I get your idea finally... Just share some thoughts here.
So the idea is, we change the problem to:

  Find two numbers in num, the xor of which equals to a given number n.

  Because this number is given, we don't need to do n^2 search, instead we try to find if n xor one num in nums = another num in nums (xor trick). So we can do it in one pass.
Then, like LC 69: Sqrt(x), we are searching this number from highest bit to lowest bit. (Greedy here)
And since result has log(n) bits, the time complexity is nlogn*/


class Solution {
public:
  int findMaximumXOR(vector<int>& nums) {
    int res = 0, mask = 0;
    for (int i = 31; i >= 0; --i) {
      mask |= 1 << i;
      set<int> prefixes;
      for (int num : nums) {
        prefixes.insert(num & mask);
      }

      int t = res | 1 << i;

      for (int prefix : prefixes) {
        if (prefixes.count(t ^ prefix)) {  // if t ^ prefix1 = prefix2, then prefix2 ^ prefix1 = t
          //Given number t, find two numbers in the array so that n1 ^ n2 = t
          res = t;
          break;
        }
      }
    }
    return res;
  }
};
