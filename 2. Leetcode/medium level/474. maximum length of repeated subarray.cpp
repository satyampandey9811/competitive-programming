// link to question - https://leetcode.com/problems/maximum-length-of-repeated-subarray/

class Solution {
public:
    int findLength(vector<int>& a, vector<int>& b) {
        int m = a.size(), n = b.size(), ans = 0;
        vector<vector<int>> dp(m, vector<int>(n));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(a[i] == b[j]) {
                    dp[i][j]++;
                    if(i > 0 and j > 0) dp[i][j] += dp[i-1][j-1];
                }
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ans;
    }
};