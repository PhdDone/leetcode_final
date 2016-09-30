//Given two numbers represented as strings, return multiplication of the numbers as a string.

class Solution {
public:
  string multiply(string num1, string num2) {
    if (num1.size() == 0 || num2.size() == 0) return 0;
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    string res(num1.size() + num2.size() + 1, '0'); //use char 0, not int 0!!
        
    for (int i = 0; i < num1.size(); ++i) {
      int carry = 0;
      int digit1 = num1[i] - '0';
      for (int j = 0; j < num2.size(); ++j) {
	int digit2 = num2[j] - '0';
	int exist = res[i+j] - '0';
	res[i+j] = digit1*digit2 + carry + exist;
	carry = res[i+j] / 10;
	res[i+j] = res[i+j] % 10 + '0';
      }
      if (carry > 0) {
	res[i+num2.size()] = carry + '0'; //store the carry for every i, j pair
      }
    }
        
    reverse(res.begin(), res.end());
    int start = 0;
    while (res[start] == '0' && start < res.size()) { //remove the prefix 0!!!
      start++;
    }
    if (start == res.size()) return "0";
    return res.substr(start, res.size() - start); //substr
  }
};
