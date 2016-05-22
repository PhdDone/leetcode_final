/*
This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.
*/

class Solution {
public:
  int shortestWordDistance(vector<string>& words, string word1, string word2) {
    int ret = words.size() - 1;
    int t1 = -1;
    int t2 = -1;

    for(int i=0;i<words.size();i++)
      {
	if(words[i]==word1)
	  {
	    t1 = i;
	    if(t2 != -1 && ret > t1 - t2)
	      {
		ret = t1 - t2;
	      }
	  }

	if(words[i]==word2)
	  {
	    t2 = i;
	    if(t1 != -1 && t1 != t2 && ret > t2 - t1)
	      {
		ret = t2 - t1;
	      }
	  }
      }

    return ret;
  }
};
