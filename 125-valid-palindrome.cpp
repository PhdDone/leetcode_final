class Solution {
public:
  bool isPalindrome(string s) {
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    int len = s.length();
    if(len <= 1)return true;
    int i = 0, j = len - 1;
    while(i <= j)
      {
	if(isAlphanumeric(s[i]) == false)
	  i++;
	else if(isAlphanumeric(s[j]) == false)
	  j--;
	else //use else here!!
	  {
	    if(isSame(s[i], s[j]) == true)
	      {i++; j--;}
	    else return false;
	  }
      }
    return true;
  }
  bool isAlphanumeric(char c)
  {
    if((c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z')||(c >= '0' && c <= '9'))
      return true;
    else return false;
  }
  bool isSame(char a, char b)
  {
    if(a >= 'A' && a <= 'Z')
      a += 32;
    if(b >= 'A' && b <= 'Z')
      b += 32;
    return a == b;
  }
};
