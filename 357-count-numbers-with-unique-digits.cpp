/*Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])
*/

//http://www.cnblogs.com/grandyang/p/5582633.html

class Solution {
public:
  int countNumbersWithUniqueDigits(int n) {
    n = min(n, 10);
    int res = 1, max = pow(10, n), used = 0;
    for (int i = 1; i < 10; ++i) {
      used |= (1 << i);
      res += search(i, max, used);
      used &= ~(1 << i);
    }
    return res;
  }
  int search(int pre, int max, int used) {
    int res = 0;
    if (pre < max) ++res;
    else return res;
    for (int i = 0; i < 10; ++i) {
      if (!(used & (1 << i))) {
	used |= (1 << i);
	int cur = 10 * pre + i;
	res += search(cur, max, used);
	used &= ~(1 << i);
      }
    }
    return res;
  }
};
