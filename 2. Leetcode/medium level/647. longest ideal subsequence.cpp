// link to question - https://leetcode.com/problems/longest-ideal-subsequence/

class Solution {
public:
    int dp[100002][27];
    int n;
    
    int go (int i, int p, string& s, int& k) {
        if (i >= n) return 0;
        int &ans = dp[i][p];
        if (ans != -1) return ans;
        
        ans = 0;
        int c = s[i] - 'a';
        
        if (abs(c - p) <= k) {
            ans = 1 + go (i + 1, c, s, k);
        }
        ans = max(ans, go (i + 1, p, s, k));
        
        return ans;
    }
    
    int longestIdealString(string s, int k) {
        n = s.size();
        memset(dp, -1, sizeof dp);
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            ans = max(ans, go (i, s[i] - 'a', s, k));
        }
        
        return ans;
    }
};