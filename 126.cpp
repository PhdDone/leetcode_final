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
