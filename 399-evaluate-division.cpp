/*
Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.

Show Company Tags
Show Tags
*/




struct MyHash
{
  std::size_t operator()(pair<string, string> const& p) const
  {
    std::size_t h1 = std::hash<std::string>{}(p.first);
    std::size_t h2 = std::hash<std::string>{}(p.second);
    return h1 ^ (h2 << 1); // or use boost::hash_combine
  }
};

class Solution {
public:
  vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
    unordered_map<pair<string,string>, double, MyHash> edges;
    unordered_set<string> nodes;
    int N = equations.size();
    for (int i = 0; i < N; ++i) {
      auto const& e = equations[i];
      nodes.insert(e.first);
      nodes.insert(e.second);
      edges[e] = values[i];
      edges[make_pair(e.second, e.first)] = 1 / values[i];
    }

    for (auto const& n1 : nodes) {
      edges[make_pair(n1, n1)] = 1;
      for (auto const& n2 : nodes) {
        for (auto const& n3 : nodes) {
          auto iter1 = edges.find(make_pair(n2, n1));
          auto iter2 = edges.find(make_pair(n1, n3));
          if (iter1 != edges.end() && iter2 != edges.end()) {
            edges[make_pair(n2, n3)] = iter1->second * iter2->second;
          }
        }
      }
    }

    vector<double> res;
    for (auto const& q : queries) {
      //res.push_back(edges[q]);
      auto iter = edges.find(q);
      if (iter != edges.end()) {
        res.push_back(iter->second);
      } else {
        res.push_back(-1.0);
      }
    }
    return res;

  }
};
