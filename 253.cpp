/*Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
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

#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
  int minMeetingRooms(vector<Interval>& intervals) {
    int n = intervals.size();
    if (n == 0) return 0;
    if (n == 1) return 1;
        
    sort(intervals.begin(), intervals.end(), cmp);
        
    vector<vector<Interval>> rooms;
    vector<Interval> room{intervals[0]};
    rooms.push_back(room);
        
    for (int i = 1; i < n; i++) {
      bool needNewRoom = true;
      for (auto iter = rooms.begin(); iter < rooms.end(); ++iter) {
	if (iter->back().end <= intervals[i].start) {
	  iter->push_back(intervals[i]);
	  needNewRoom = false;
	  break;
	}
      }
      if (needNewRoom) {
	vector<Interval> room{intervals[i]};
	rooms.push_back(room);
      }
    }
    return rooms.size();
  }
    
  static bool cmp(const Interval& a, const Interval& b) {
    return a.start < b.start;
  }
};

int main() {
  Interval a(1, 5);
  Interval b(8, 9);
  Interval c(8, 9);
  vector<Interval> ins {a, b, c};
  
  Solution s;
  cout << s.minMeetingRooms(ins);
  return 0;
}
