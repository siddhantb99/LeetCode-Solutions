/*
Number of Islands

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        stack<pair<int, int>> s;
        int n = grid.size();
        if(n == 0)
            return 0;
        int m = grid[0].size();
        int ans = 0;
        int i, j;
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    s.push(make_pair(i ,j));
                    while(!s.empty()){
                        auto k = s.top();
                        s.pop();
                        grid[k.first][k.second] = '0';
                        if(k.first - 1 > -1)
                            if(grid[k.first - 1][k.second] == '1')
                                s.push(make_pair(k.first - 1, k.second));
                        
                        if(k.first + 1 < n)
                            if(grid[k.first + 1][k.second] == '1')
                                s.push(make_pair(k.first + 1, k.second));
                        
                        if(k.second + 1 < m)
                            if(grid[k.first][k.second + 1] == '1')
                                s.push(make_pair(k.first, k.second + 1));
                        
                        if(k.second - 1 > -1)
                            if(grid[k.first][k.second - 1] == '1')
                                s.push(make_pair(k.first, k.second - 1));     
                    }
                }
            }
        }
        return ans;
    }
};
