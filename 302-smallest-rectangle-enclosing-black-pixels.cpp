/*
An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

For example, given the following image:

[
  "0010",
  "0110",
  "0100"
]
and x = 0, y = 2,
Return 6.
*/

//http://www.cnblogs.com/grandyang/p/5268775.html

// DFS
class Solution {
public:
  int minArea(vector<vector<char>>& image, int x, int y) {
    int left = y, right = y, up = x, down = x;
    dfs(image, x, y, left, right, up, down);
    return (right - left + 1) * (down - up + 1);
  }
  void dfs(vector<vector<char>> &image, int x, int y, int &left, int &right, int &up, int &down) {
    if (x < 0 || x >= image.size() || y < 0 || y >= image[0].size() || image[x][y] != '1') return;
    left = min(left, y);
    right = max(right, y);
    up = min(up, x);
    down = max(down, x);
    image[x][y] = '2'; //trick, change the value so that we don't need to use a visited
    dfs(image, x + 1, y, left, right, up, down);
    dfs(image, x - 1, y, left, right, up, down);
    dfs(image, x, y + 1, left, right, up, down);
    dfs(image, x, y - 1, left, right, up, down);
  }
};
