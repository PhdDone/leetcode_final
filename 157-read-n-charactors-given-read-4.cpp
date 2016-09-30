/*The API: int read4(char *buf) reads 4 characters at a time from a file.

  The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

  By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

    Note:
The read function will only be called once for each test case.
*/

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
    int len = 0;
    int m = INT_MAX; // m should be a number that larger then 4
    while(len+4<=n) {
      m = read4(buf+len);
      len += m;
      if(m<4) break;
    }
    if(len==n || m<4) return len;

    char *remain = new char[4]; //prevent read4 writes buf variable but out of bound, get a new buf
    m = min(read4(remain),n-len); //should get the smaller one to be the number of bites left
    // since 1. read4 will still return 4 but we need 3.
    // 2. read4 will return 1 but we need 3 
    for(int i=0; i<m; i++) buf[len++] = remain[i];
    delete remain;
        
    return len;
  }
};



class Solution {
public:
  /**
   * @param buf Destination buffer
   * @param n   Maximum number of characters to read
   * @return    The number of characters read
   */
  int read(char *buf, int n) {
    int len = 0;
    int oneTry = 0;
    while (len + 4 < n) {
      oneTry = read4(buf + len);
      len += oneTry;
      if (oneTry < 4) break;
    }
    if (len == n || oneTry < 4) return len;

    char new_buf[5] = {};
    char *remain = new char[5];
    m = min(read4(remain),n-len);
    for(int i=0; i<m; i++) buf[len++] = remain[i];
    delete remain;

    return len;
  }
};
