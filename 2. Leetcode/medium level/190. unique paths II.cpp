// link to question - https://leetcode.com/problems/unique-paths-ii/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int m = a.size();
        if(m == 0) return 0;
        int n = a[0].size();
        if(n == 0) return 1;        
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = a[0][0] == 0 ? 1 : 0;
        
        for(int i = 1; i < n; i++) {
            if(a[0][i] == 1) dp[0][i] = 0;
            else dp[0][i] = dp[0][i-1];
        }        
        for(int i = 1; i < m; i++) {
            if(a[i][0] == 1) dp[i][0] = 0;
            else dp[i][0] = dp[i-1][0];
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(a[i][j] == 0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                else 
                    dp[i][j] = 0;
            }
        }
        
        return dp[m-1][n-1];
    }
};