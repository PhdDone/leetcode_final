/*Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5]

*/


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        int BeginX = 0;
        int EndX = matrix.size() - 1;
        int BeginY = 0;
        int EndY = matrix[0].size() - 1;
        
        while (true) {
	//from left to right
            for (int j = BeginY; j <= EndY; ++j) result.push_back(matrix[BeginX][j]);
            //update BeginX here!!!
            if (++BeginX > EndX) break;
	//from top to bottom
            for (int i = BeginX; i <= EndX; ++i) result.push_back(matrix[i][EndY]);
            if (BeginY > --EndY) break;
	//from left to right
            for (int j = EndY; j >= BeginY; --j) result.push_back(matrix[EndX][j]);
            if (BeginX > --EndX) break;
	//from bottom to top
            for (int i = EndX; i >= BeginX; --i) result.push_back(matrix[i][BeginY]);
            if (++BeginY > EndY) break;
        }
        return result;
    }
};
