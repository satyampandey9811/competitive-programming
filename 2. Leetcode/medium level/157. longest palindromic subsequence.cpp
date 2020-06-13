// link to question - https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution {
public:
    int longestPalindromeSubseq(string a) {
        string b = a;
        reverse(b.begin(), b.end());
        int m = a.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1));
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= m; j++) {
                if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[m][m];
    }
};