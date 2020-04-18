/*
Minimum Path Sum
Solution
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1?3?1?1?1 minimizes the sum.
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int size = grid.size();
        if(size == 0)
            return 0;
        int size1 = grid[0].size();
        if(size1 == 0)
            return 0;
        int i,j;
        for(i = 1; i < size; i++){
            grid[i][0] += grid[i - 1][0];
        }
        for(i = 1; i < size1; i++){
            grid[0][i] += grid[0][i - 1];
        }
        for(i = 1; i < size; i++){
            for( j = 1; j < size1; j++){
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[size - 1][size1 - 1];
    }
};
