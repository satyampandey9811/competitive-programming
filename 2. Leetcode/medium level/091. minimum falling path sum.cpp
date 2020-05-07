// link to question - https://leetcode.com/problems/minimum-falling-path-sum/

class Solution {
public:        
    int minFallingPathSum(vector<vector<int>>& a) {        
        int m = a.size(), n = a[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        for(int j = 0; j < n; j++) {
            dp[m - 1][j] = a[m - 1][j];
        }
        
        for(int i = m - 2; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                int p = dp[i + 1][j];
                if(j - 1 >= 0)
                    p = min(p, dp[i + 1][j - 1]);
                if(j + 1 < n)
                    p = min(p, dp[i + 1][j + 1]);
                dp[i][j] = a[i][j] + p;
            }
        }
        int ans = *min_element(dp[0].begin(), dp[0].end());
        return ans;
    }
};