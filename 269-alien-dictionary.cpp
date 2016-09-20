/*
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.
 */


//http://www.cnblogs.com/jcliBlogger/p/4758761.html

Solution {
  typedef unordered_map<char, unordered_set<char>> Graph;
 public:
  string alienOrder(vector<string>& words) {
    if (words.size() == 1) return words[0]; //!!! only one word !!!
    Graph g = makeGraph(words);
    unordered_map<char, int> indegree = computeIndegree(g);
    
    queue<char> zeroIndegreeChar;
    string order;
    for (const auto& x : indegree) {
      if (x.second == 0) {
        zeroIndegreeChar.push(x.first);
            }
        }
        
        //while (!zeroIndegreeChar.empty()) { //!!!! not until the empty !!!
        int N = indegree.size();
        for (int i = 0; i < N; ++i) {
            if (zeroIndegreeChar.empty()) return "";  // once it's empty before we go over all the nodes, circle!! clear order!!
            char x = zeroIndegreeChar.front();
            zeroIndegreeChar.pop();
            order += x;
            auto children = g[x];
            for (auto child : children) {
                if (indegree[child] > 0)
                    --indegree[child];
                    if (indegree[child] == 0)
                        zeroIndegreeChar.push(child);
            }
        }
        return order;
    }
private:
    Graph makeGraph(vector<string> words) {
        Graph g;
        int N = words.size();
        for (int i = 1; i < N; ++i) {
            string word1 = words[i-1];
            string word2 = words[i];
            bool found = false;
            int l1 = word1.size();
            int l2 = word2.size();
            int l = max(l1, l2);
            for (int j = 0; j < l; ++j) {
                if (j < l1 && g.find(word1[j]) == g.end()) { //insert every char to graph, no matter found is true or not
                    g[word1[j]] = unordered_set<char>{};
                }
                if (j < l2 && g.find(word2[j]) == g.end()){
                    g[word2[j]] = unordered_set<char>{};
                }
                if (j < l1 && j < l2 && word1[j] != word2[j] && !found) {
                    g[word1[j]].insert(word2[j]); //insert as proceed charactor; w1[j] -> {w2[j]....}
                    found = true;
                }
            }
        }
        return g;
    }
    
    unordered_map<char, int> computeIndegree (const Graph& g) {
        unordered_map<char, int> indegree;
        for (auto x : g) {
            if (indegree.find(x.first) == indegree.end()) {
                indegree[x.first] = 0;
            }
            for (auto y : x.second) {
                ++indegree[y];
            }
        }
        return indegree;
    }
};
