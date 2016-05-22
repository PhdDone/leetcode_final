/*
  Given a collection of intervals, merge all overlapping intervals.

  For example,
  Given [1,3],[2,6],[8,10],[15,18],
  return [1,6],[8,10],[15,18].
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

//sort the intervals by first element

class Solution {
public:
  vector<Interval> merge(vector<Interval>& intervals) {
    int n = intervals.size();
    if (n == 0) return vector<Interval>{};
        
    sort(intervals.begin(), intervals.end(), cmp);
    vector<Interval> res;
    res.push_back(intervals[0]);
    for (int i = 1; i < n; ++i) {
      if (res.back().end >= intervals[i].start) {
	res.back().end = max(res.back().end, intervals[i].end);
      }
      else {
	res.push_back(intervals[i]);
      }
    }
    return res;
  }
    
  static bool cmp(const Interval& a, const Interval& b) {
    return a.start < b.start;
  }
};
