#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  vector<string> generatePossibleNextMoves(string s) {
    int end = s.size();
    if (end == 1) return vector<string>{};
        
    vector<string> results;
    string path;
    DFS(results, 1, end, s);
    return results;
  }
    
  void DFS(vector<string>& result, int start, int end, string& s) {
    if (start >= end) return;
    if (s[start - 1] == s[start]) { //able to flip
      if (s[start - 1] == '+') {
	s[start - 1] = s[start] = '-';
	result.push_back(s);
      	s[start - 1] = s[start] = '+';
	DFS(result, start + 1, end, s);
      }
      else
	DFS(result, start + 2, end, s);
    }
    else
      DFS(result, start + 1, end, s);
  }
};

int main() {
  Solution s;
  string test = "---+++-+++-+";
  auto result = s.generatePossibleNextMoves(test);
  for (auto r: result) {
    cout << r << endl;
  }
  return 0;
}

//solution 2, no recursion
class Solution {  
public:  
  vector<string> generatePossibleNextMoves(string s) {  
    vector<string> res;  
    if (s.length() <= 1) {  
      return res;  
    }  
    for (int i = 0; i < s.length() - 1; ++i) {  
      if (s[i] == s[i+1] and s[i] == '+') {  
	s[i] = s[i+1] = '-';  
	res.push_back(s);  
	s[i] = s[i+1] = '+';  
      }  
    }  
    return res;  
  }  
};  
