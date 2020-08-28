// link to question - https://leetcode.com/problems/dungeon-game/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        
        dp[m-1][n-1] = a[m-1][n-1] >= 0 ? 1 : -a[m-1][n-1] + 1;
        
        for(int i = m - 2; i >= 0; i--) {
            dp[i][n-1] = max(1, dp[i+1][n-1] - a[i][n-1]);
        }
        
        for(int i = n - 2; i >= 0; i--) {
            dp[m-1][i] = max(1, dp[m-1][i+1] - a[m-1][i]);
        }
        
        for(int i = m - 2; i >= 0; i--) {
            for(int j = n - 2; j >= 0; j--) {
                dp[i][j] = max(1, min(dp[i+1][j] - a[i][j], dp[i][j+1] - a[i][j]));
            }            
        }
        
        return dp[0][0];
    }
};