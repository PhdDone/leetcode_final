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
	else //use else here!!   both s[i] and s[j] are alphanumeric
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

  //lowercaser
  bool isSame(char a, char b)
  {
    int Atoa = 'a' - 'A';
    if(a >= 'A' && a <= 'Z')
      a += Atoa;
    if(b >= 'A' && b <= 'Z')
      b += Atoa;
    return a == b;
  }
};
