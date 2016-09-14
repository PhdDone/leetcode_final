class Solution {
public:
  int mySqrt(int x) {
    int left = 1, right = x / 2; //if x < 2
    int last_mid = 0;
    if (x < 2) return x; //??
    while (left <= right) { // less and equal!!!
      int mid = left + (right - left) / 2;
      if (x / mid == mid) return mid;
      if (x / mid > mid) {
        left = mid + 1;
        last_mid = mid;
      } else {
        right = mid - 1;
      }
    }
    return last_mid;
  }
};
