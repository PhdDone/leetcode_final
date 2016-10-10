/*There are a total of n courses you have to take, labeled from 0 to n - 1.

  Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

  Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

  There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

  For example:

  2, [[1,0]]
  There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

  4, [[1,0],[2,0],[3,1],[3,2]]
  There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].

  Note:
  The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
*/

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    unordered_map<int, int> indegree;
    unordered_map<int, vector<int>> children;
    vector<int> res;
    for (int i = 0; i < numCourses; ++i) {
      indegree[i] = 0;
    }
    for (const auto& p : prerequisites) {
      ++indegree[p.first];
      children[p.second].push_back(p.first);
    }

    queue<int> q;

    for (auto c : indegree) {
      if (c.second == 0) {
        q.push(c.first);
      }
    }

    while (!q.empty()) {
      int c = q.front();
      q.pop();
      res.push_back(c);
      for (int child : children[c]) { //update indegree for c's children
        if (indegree[child] > 0) {
          --indegree[child];
          if (indegree[child] == 0) {
            q.push(child);
          }
        }
      }
    }
    if (res.size() == numCourses) return res; //check loop!!!!!!!!!!!!!
    return vector<int>{};
  }
};
