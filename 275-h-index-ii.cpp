//Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?

class Solution {
public:
  int hIndex(vector<int>& citations) {
    int h = citations.size();
    //for (int i = 0; i < h; ++i) { //don't reuse h here!!
    int N = citations.size(); //get the size N out first, otherwise timeout!!
    for (int i = 0; i < N; ++i) {
      if (citations[i] >= h) {
        return h;
      } else {
        --h;
      }
    }
    return h;
  }
};
