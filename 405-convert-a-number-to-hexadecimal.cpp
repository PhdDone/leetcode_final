/*
Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

Note:

All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed integer.
You must not use any method provided by the library which converts/formats the number to hex directly.
Example 1:

Input:
26

Output:
"1a"
Example 2:

Input:
-1

Output:
"ffffffff"
*/

class Solution {
public:
  string toHex(int num) {
    if (num == 0) return "0";
    string res;
    //cout << sizeof(int) << endl;
    while (num && res.length() != 8) { //because the right shift will fill in 1, num will never reach 0
      int hex = num & 15;
      if (hex < 10) res.push_back(hex + '0');
      else {
        res.push_back(hex + 'a' - 10);
      }
      cout << num << endl;
      num >>= 4; //if a negative number, 1 will be filled
    }

    reverse(res.begin(), res.end());
    return res;
  }
};
