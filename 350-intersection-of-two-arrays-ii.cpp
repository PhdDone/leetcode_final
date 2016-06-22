class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> res;
    int N = min(nums1.size(), nums2.size());
    if (nums1.size() > nums2.size()) swap(nums1, nums2);
    int i = 0;
    int j = 0;
    while (i < N ) {
      if (nums1[i] < nums2[j]) {
	++i;
	continue;
      }
      if (nums1[i] > nums2[j]) {
	++j;
	continue;
      }
      res.push_back(nums1[i]);
      ++i;
      ++j;
    }
    return res;
  }
};
