// link to question - https://leetcode.com/problems/cherry-pickup-ii/

class Solution {
public:
    int help(int r, int c1, int c2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        if(r == grid.size()) return 0;
        if(c1 < 0 or c2 < 0 or c1 >= grid[0].size() or c2 >= grid[0].size()) return 0;
        
        if(dp[r][c1][c2] != -1) return dp[r][c1][c2];
        
        int ans = 0;
        if(c1 == c2) ans += grid[r][c1];
        else ans += grid[r][c1] + grid[r][c2];
        
        int fans = 0;
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                fans = max(fans, help(r + 1, c1 + i, c2 + j, grid, dp));
            }
        }
        
        return dp[r][c1][c2] = ans + fans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
        return help(0, 0, n - 1, grid, dp);
    }
};