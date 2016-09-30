#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<pair<int, int>> getSkyline(vector<vector<int>> &buildings) {
    vector<pair<int, int>> h, res;
    multiset<int> m;
    int pre = 0, cur = 0;
    for (auto &a : buildings) {
      h.push_back({a[0], -a[2]});
      h.push_back({a[1], a[2]});
    }
    sort(h.begin(), h.end());
    m.insert(0);
    for (auto &a : h) {
      if (a.second < 0) // make the left height smaller than zero, to distinguish left and right
        m.insert(-a.second);
      else
        m.erase(m.find(a.second)); // if it's a right node, then remove the left node
      //!!! after removing the left node, the cur may change, because then we query the multiset, cur will
      //be the cur highest hight
      cur = *m.rbegin(); //get the current highest height
      if (cur != pre) {
        res.push_back({a.first, cur});
        pre = cur;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> b1 = {1, 4, 1};
  vector<int> b2 = {2, 3, 2};
  vector<vector<int>> b = {b1, b2};
  auto r = s.getSkyline(b);
  for (auto x : r) {
    cout << x.first << ", " << x.second << endl;
  }
  return 0;
}
