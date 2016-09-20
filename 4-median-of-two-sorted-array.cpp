/*There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

  Example 1:
                                   nums1 = [1, 3]
  nums2 = [2]

  The median is 2.0
  Example 2:
                                   nums1 = [1, 2]
  nums2 = [3, 4]

  The median is (2 + 3)/2 = 2.5
*/
class Solution {
  double findKth(vector<int>& nums1, int startIndex1, vector<int>& nums2, int startIndex2, int k) {

    int N1 = nums1.size() - startIndex1;
    int N2 = nums2.size() - startIndex2;
    if (N1 > N2) {
      return findKth(nums2, startIndex2, nums1, startIndex1, k);
    }
    if (N1 == 0) {
      return nums2[k-1]; //terminal condition
    }
    if (k == 1) {
      return min(nums1[startIndex1], nums2[startIndex2]);
    }
    int i1 = min(N1, k/2); //try get k/2 elements from nums1
    int i2 = k - i1; // try get k/2 elemens from nums2 (or left)
    //cout << i1 << " " << i2 << endl;
    if (nums1[startIndex1 + i1 - 1] < nums2[startIndex2 + i2 - 1]) //remove k/2 elements from nums1, remeber to -1 !!! index!!
      return findKth(nums1, startIndex1+i1, nums2, startIndex2, k - i1); // k-i1! i1 elements are removed
    else if (nums1[startIndex1 + i1 - 1] > nums2[startIndex2 + i2 - 1])
      return findKth(nums1, startIndex1, nums2, startIndex2 + i2, k - i2);
    else
      return nums1[startIndex1 + i1 -1]; // if equal, then that's the K!!
  }
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int N1 = nums1.size();
    int N2 = nums2.size();
    int total = N1 + N2;
    if (total & 0x1) {
      return findKth(nums1, 0, nums2, 0, total / 2 + 1);
    } else {
      return (findKth(nums1, 0, nums2, 0, total/2) + findKth(nums1, 0, nums2, 0, total/2 + 1)) / 2;
    }
  }
};
