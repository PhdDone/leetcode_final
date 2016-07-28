class Solution {
public:
  vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<pair<int, int>> res;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> Q;

    int N = nums1.size();
    int M = nums2.size();
    N = min(N, k);
    M = min(M, k);

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (Q.size() < k) {
          //std::pair <int,int> foo;
          //foo = std::make_pair<int, int>(num1[i], nums2[j])
          Q.push({nums1[i], nums2[j]});
        } else {
          auto top = Q.top(); // only need to cmp with top cuz it's a max heap
          if (top.first + top.second > nums1[i] + nums2[j]) {
            Q.push({nums1[i], nums2[j]});
            Q.pop();
          }
        }
      }
    }

    while (!Q.empty()) {
      res.push_back(Q.top());
      Q.pop();
    }
    return res;
  }

  // Use max heap so the root(in priority_queue it's the front) is the max of all the nodes in the heap
  // for priority_queue cmp, if the cmp(a, b) return true, it means a "<" b
  // if cmp(a, b) return true, then put a after b
  // here we don't really care about the sequence in the priority queue,
  // what we need is Q.top() is the max of the Q
  // so everytime we only need to compare with the top
  // if the new node is smaller than the top, then kick the top out and insert the new node
  struct cmp {
    bool operator() (pair<int, int> a, pair<int, int> b) {
      return a.first + a.second < b.first + b.second;
    }
  };
};
