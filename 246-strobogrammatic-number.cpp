/*A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

For example, the numbers "69", "88", and "818" are all strobogrammatic.
*/

class Solution {
public:
  bool isStrobogrammatic(string num) {

    int l = 0;
    int r = num.length()-1;

    while(l<=r)
      {
	if(
	   (num[l] == '6' && num[r] == '9')||
	   (num[l] == '9' && num[r] == '6')||
	   (num[l] == '8' && num[r] == '8')||
	   (num[l] == '1' && num[r] == '1')||
	   (num[l] == '0' && num[r] == '0')
	   )
	  {
	    l++;
	    r--;
	  }
	else
	  return false;

      }

    return true;
  }
};
