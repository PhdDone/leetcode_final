


// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
  /**
   * @param buf Destination buffer
   * @param n   Maximum number of characters to read
   * @return    The number of characters read
   */
  int read(char *buf, int n) {
    int i = 0;
    // i is the index of buf
    // i4 is the index of current cache
    // n4 is the end of current cache
    // char4 is the cache
    // i4 < n4 means we need to copy from cache to buf
    // if the all the character in char4 is copied to buf(i4 == n4), read new stuff: i4 = 0, n4 = read4(char4)
    while ((i < n) && ((i4 < n4) || ((i4 = 0) < (n4 = read4(char4))))) {
      buf[i++] = char4[i4++];
    }
    return i;
  }
    
  int i4 = 0;
  int n4 = 0;
  char char4[4];
};
