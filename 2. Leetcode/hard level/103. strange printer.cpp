// link to question - https://leetcode.com/problems/strange-printer/

class Solution {
public:
    int dp[101][101][2];
    
    int go(int l, int r, int p, string& s) {
        if (l > r) return 0;
        int &ans = dp[l][r][p];
        if (ans != -1) return ans;
        
        while (l + 1 <= r and s[l + 1] == s[l]) l++;
        ans = go(l + 1, r, 0, s);
        
        for (int i = l + 1; i <= r; i++) {
            if (s[i] == s[l]) {
                ans = min(ans, go(i, r, 1, s) + go(l + 1, i - 1, 0, s));
            }
        }
        
        if (p == 0) ans++;
        return ans;
    }
    
    int strangePrinter(string s) {
        memset(dp, -1, sizeof dp);
        return go(0, s.size() - 1, 0, s);
    }
};