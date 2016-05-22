/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
					       For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

					       Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/

//http://blog.csdn.net/cinderella_niu/article/details/42235417
using namespace boost;

class Solution {
public:
  int compareVersion(string version1, string version2) {
    int ret = 0;
    if(version1.size() == 0 || version2.size() == 0) return ret;
        
    vector<string> v1;
    vector<string> v2;
        
    boost::split(v1, version1, boost::is_any_of("."));
    boost::split(v2, version2, boost::is_any_of("."));
        
    int len1 = v1.size();
    int len2 = v2.size();
        
    int i = 0;
    for(ret == 0 && (i < len1 || i < len2))
      {
	int x1 = i < len1 ? stoi(v1[i]) : 0;
	int x2 = i < len2 ? stoi(v2[i]) : 0;
	if(x1 > x2)
	  ret = 1;
	else if(x1 < x2)
	  ret = -1;
	else
	  i++;  
      }
        
    return ret;
  }
};


class Solution {
public:
  int compareVersion(string version1, string version2) {
    istringstream st1(version1);
    istringstream st2(version2);
    string token;
    vector<int> d1;
    vector<int> d2;
    while (getline(st1,token,'.')){
      stringstream os1;
      os1.str(token);
      int tmp;
      os1 >> tmp;
      d1.push_back(tmp);
    }
    while (getline(st2,token,'.')){
      stringstream os2;
      os2<<token;
      int tmp;
      os2 >> tmp;
      d2.push_back(tmp);
    }
         
    int n1 = d1.size();
    int n2 = d2.size();
         
    for (int i=0;i<min(n1,n2);i++){
      if (d1[i]>d2[i]){ return 1;}
      if (d1[i]<d2[i]){ return -1;}
    }
         
    if (n1<n2){
      for (int i=n1;i<n2;i++){
	if (d2[i]!=0){return -1;}
      }
      return 0;
    }
    if (n1>n2){
      for (int i=n2;i<n1;i++){
	if (d1[i]!=0){return 1;}
      }
      return 0;
    }
    if (n1==n2){return 0;}
  }
};
