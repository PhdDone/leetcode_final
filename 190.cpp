/*Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

  Follow up:
  If this function is called many times, how would you optimize it?

  Related problem: Reverse Integer
*/

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    queue<int> S; //use queue, not stack
    for (int i = 0; i < 32; ++i) {
      if (n % 2 == 1)
	S.push(1);
      else
	S.push(0);
      n = n >> 1; //remeber to update n
    }
    uint32_t result = 0;
    while (!S.empty()) {
      result = result << 1;
      result += S.front();
      S.pop();
    }
    return result;
  }
};
