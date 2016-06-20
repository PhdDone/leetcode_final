/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int R = matrix.size();
        if (R == 0) return;
        
        int C = matrix[0].size();
        
        int col_start = 0;
        
        for (int i = 0; i < R; ++i) {
            col_start++;
            for (int j = col_start; j < C; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < R; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};