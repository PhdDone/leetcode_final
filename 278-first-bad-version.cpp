//Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    int right = n;
    int left = 1;
        
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (isBadVersion(mid)) {
	right = mid - 1;
      }
      else
	left = mid + 1;
    }
    return left; //just have to remeber
  }
};
