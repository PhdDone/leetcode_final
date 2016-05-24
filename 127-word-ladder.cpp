/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
*/

#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <queue>
using namespace std;



class Solution {
public:
  int ladderLength(string start, string end, unordered_set<string> &dict) {
    dict.insert(end); //!!! insert the terminat in to dict !!!
    queue<pair<string,int>> q;
    q.push(make_pair(start,1));  //re
    while(!q.empty()) {
      string s = q.front().first;
      int len = q.front().second;
      if(s==end) return len;
      q.pop();
      vector<string> neighbors = findNeighbors(s, dict);
      for(int i=0; i<neighbors.size(); i++) 
	q.push(make_pair(neighbors[i],len+1));
    }
    return 0;
  }
    
  vector<string> findNeighbors(string s, unordered_set<string> &dict) {
    vector<string> ret;
    for(int i=0; i<s.size(); i++) { //iterate on charactors instead of on dictionary
      char c = s[i];
      for(int j=0; j<26; j++) {
	if(c=='a'+j) continue; // skip same charactor
	s[i] = 'a'+j;
	if(dict.count(s)) { // count or find(s) != dict.end()
	  ret.push_back(s);    
	  dict.erase(s);    // don't need another one to remember the visited
	}
      }
      s[i] = c; // remeber to change back
    }
    return ret;
  }
};

int main() {
  unordered_set<string> wordList;
  // wordList.insert("hot");
//   //wordList.insert("cog");
//   wordList.insert("dot");
//   wordList.insert("dog");
//   wordList.insert("hit");
//   wordList.insert("lot");
//   wordList.insert("log");
//   string bword = "hit";
//   string eword = "cog";

  wordList.insert("b");
  string bword = "a";
  string eword = "c";
  Solution s;
  cout << s.ladderLength(bword, eword, wordList);
  return 0;
}
  
/* http://www.cnblogs.com/TenosDoIt/p/3443512.html */
