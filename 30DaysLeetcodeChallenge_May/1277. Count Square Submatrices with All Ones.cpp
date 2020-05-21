/*
Count Square Submatrices with All Ones
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.
*/
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0 ) );
        int i, j;
        int result = 0;
        for(i = 0; i < m; i++)
            for(j = 0; j < n; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j];
                } else if( matrix[i][j] == 1 ) {
                    dp[i][j] = min(dp[i - 1][j], min( dp[i - 1][j - 1], dp[i][j - 1] ) ) + 1;
                }
                result += dp[i][j];
            }

        return result;
    }
};
