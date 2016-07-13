/*
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
Example 2:
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.
*/

//https://www.hrwhisper.me/leetcode-reconstruct-itinerary/

class Solution {
public:
  vector<string> findItinerary(vector<pair<string, string>> tickets) {
    unordered_map<string, map<string, int>> M; //std::map will sort the string
    int N = tickets.size();
    for (auto t : tickets) {
      ++M[t.first][t.second];
    }
    vector<string> res;
    res.push_back("JFK");
    buildIt(M, "JFK", res, N + 1);
    return res;

  }

  bool buildIt(unordered_map<string, map<string, int>>& M, string start, vector<string>& res, int N) {
    if (res.size() == N) {
      return true;
    }
    for (auto i = M[start].begin(); i != M[start].end(); ++i) {
      if (i->second > 0) {
        res.push_back(i->first);
        --i->second;
        if (buildIt(M, i->first, res, N)) return true; //jingmiao, or tail recursion
        res.pop_back();
        ++i->second;
      }
    }
    return false;
  }
};
