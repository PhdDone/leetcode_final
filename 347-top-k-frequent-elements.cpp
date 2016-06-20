/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 = k = number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/


typedef pair<int, int> Node; //frequency, num

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        for (int num : nums) {
            frequency[num]++;
        }
        priority_queue<Node, vector<Node>, greater<Node>> q; //use greater to define a min heap
        for (auto& f : frequency) {
            if (q.size() < k) {
                q.push(make_pair(f.second, f.first));
            }
            else {
                if (q.top().first < f.second) {
                    q.pop();
                    q.push(make_pair(f.second, f.first));
                }
            }
        }
        vector<int> res;
        while (!q.empty()) {
            auto node = q.top();
            q.pop();
            res.push_back(node.second);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};