//Check leetcode double queue solution

class Solution {
public:
  typedef unordered_set<string>::iterator HashIter;
  vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
    // Note: The Solution object is instantiated only once and is reused by each test case.
    queue<string> Q;
    Q.push(start); Q.push("");
    bool hasFound = false;
    unordered_map<string,vector<string> >prePath;
    unordered_set<string> hashtable;
    while(Q.empty() == false)
      {
	string str = Q.front(), strCopy = str;
	Q.pop();
	if(str != "")
	  {
	    int strLen = str.length();
	    for(int i = 0; i < strLen; i++)
	      {
		char tmp = str[i];
		for(char c = 'a'; c <= 'z'; c++)
		  {
		    if(c == tmp)continue;
		    str[i] = c;
		    if(str == end)
		      {
			hasFound = true;
			prePath[end].push_back(strCopy);
			//æåääææçèå，åååèçååèæåæåè
			goto END;
		      }
		    if(dict.find(str) != dict.end())
		      {
			prePath[str].push_back(strCopy);
			//äèbfsææåéåçåçäååéå
			if(hashtable.find(str) == hashtable.end())
			  {Q.push(str); hashtable.insert(str);}
		      }
		  }
		str[i] = tmp;
	      }
	  }
	else if(Q.empty() == false)//ååååççå，ääææåäåççå
	  {
	    if(hasFound)break;
	    //éåèåæåç，æbfsääåæåéåçåçäååäåé
	    for(HashIter ite = hashtable.begin(); ite != hashtable.end(); ite++)
	      dict.erase(*ite);
	    hashtable.clear();
	    Q.push("");
	  }
      END: ;
      }
    vector<vector<string> > res;
    if(prePath.find(end) == prePath.end())return res;
    vector<string> tmpres;
    tmpres.push_back(end);
    ConstructResult(prePath, res, tmpres, start, end);
    return res;
  }
    
private:
  // recursively reconstruct the path
  void ConstructResult(unordered_map<string,vector<string> > &prePath, 
		       vector<vector<string> > &res, vector<string> &tmpres, 
		       string &start, string &end)
  {
    if(start == end)
      {
	reverse(tmpres.begin(), tmpres.end());
	res.push_back(tmpres);
	reverse(tmpres.begin(), tmpres.end());
	return;
      }
    vector<string> &pre = prePath[end];
    for(int i = 0; i < pre.size(); i++)
      {
	tmpres.push_back(pre[i]);
	ConstructResult(prePath, res, tmpres, start, pre[i]);
	tmpres.pop_back();
      }
        
  }
};




class Solution {
public:
  unordered_map<string, vector<string>> father;
  unordered_set<string> visited;
  unordered_set<string> cur, next;
  void getPath(vector<vector<string>>& res, vector<string>& path, const string& beginWord, const string& endWord, unordered_map<string, vector<string>> father) {
    if (beginWord == endWord) {
      res.push_back(path);
      reverse(res.back().begin(), res.back().end());
      return;
    }
    auto const& fathers = father[endWord];
    for (auto const& f : fathers) {
      path.push_back(f);
      getPath(res, path, beginWord, f, father);
      path.pop_back();
    }
  }

  bool isTarget(const string& s, const string& endWord) {
    return s == endWord;
  }

  vector<string> getNextStates(const string& curString, const unordered_set<string>& wordList, const string& endWord) {
    vector<string> res;
    int N = curString.size();
    string tmpString = curString;
    for (int i = 0; i < N; ++i) {
      for (char x = 'a'; x <= 'z'; ++x) {
        if (x == tmpString[i]) continue;
        else {
          swap(tmpString[i], x);
          if (visited.count(tmpString) == 0 && (wordList.count(tmpString) > 0 || tmpString == endWord)) {
            res.push_back(tmpString);
          }
          swap(tmpString[i], x);
        }
      }
    }
    return res;
  }

  vector<vector<string>>       father[next_state].push_back(word); //backtrace pointer
}
  }

cur.clear();
swap(cur, next);
}



class Solution {
public:
  unordered_map<string,vector<string> > mp; // result map, string to it's next state
  vector<vector<string> > res;
  vector<string> path;

  void findDict2(string str, unordered_set<string> &dict,unordered_set<string> &next_lev){
    int sz = str.size();
    string s = str;
    for (int i=0;i<sz;i++){
      s = str;
      for (char j = 'a'; j<='z'; j++){
        s[i]=j;
        if (dict.find(s)!=dict.end()){
          next_lev.insert(s);
          mp[s].push_back(str);
        }
      }
    }
  }

  void output(string &start,string last){
    if (last==start){
      reverse(path.begin(),path.end());
      res.push_back(path);
      reverse(path.begin(),path.end());
    }else{
      for (int i=0;i<mp[last].size();i++){
        path.push_back(mp[last][i]);
        output(start,mp[last][i]);
        path.pop_back();
      }
    }
  }

  vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
    mp.clear();
    res.clear();
    path.clear();

    dict.insert(start);
    dict.insert(end);

    unordered_set<string> cur_lev;
    cur_lev.insert(start);
    unordered_set<string> next_lev;
    path.push_back(end);


    while (true){
      for (auto it = cur_lev.begin();it!=cur_lev.end();it++){dict.erase(*it);} //delete previous level words!!!
      // by deleting the words, we will not go loop!!

      for (auto it = cur_lev.begin();it!=cur_lev.end();it++){  //find current level words
        findDict2(*it,dict,next_lev);
      }

      if (next_lev.empty()){return res;}

      if (next_lev.find(end)!=dict.end()){ //if find end string
        output(start,end);
        return res;
      }

      cur_lev.clear();
      cur_lev = next_lev;
      next_lev.clear();
    }
    return res;
  }
};
