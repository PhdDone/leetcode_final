//http://bangbingsyb.blogspot.com/2014/11/leetcode-clone-graph.html
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr) return node;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> oldToNew;
        queue<UndirectedGraphNode*> q;
        auto n1 = node;
        auto n2 = new UndirectedGraphNode(n1->label);
        oldToNew[n1] = n2;
        q.push(n1);
        
        while (!q.empty()) {
            auto n1 = q.front();
            q.pop();
            int N = n1->neighbors.size();
            auto n2 = oldToNew[n1];
            for (int i = 0; i < N; ++i) {
                auto nb = n1->neighbors[i];
                if (oldToNew.count(nb)) { //current neighbor is in the map (already visited)
                    n2->neighbors.push_back(oldToNew[nb]);
                }
                else {
                    auto nb2 = new UndirectedGraphNode(nb->label);
                    oldToNew[nb] = nb2;
                    n2->neighbors.push_back(nb2);
                    q.push(nb); //not visited yet, push to queue
                }
            }
        }
        return oldToNew[node];
    }
}; 