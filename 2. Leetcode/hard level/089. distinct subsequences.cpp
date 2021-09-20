// link to question - https://leetcode.com/problems/distinct-subsequences/

class Solution {
public:
    int dp[1001][1001];
    int m, n;
    
    int go(int i, int j, string& s, string& t) {
        if(j == n) return 1;
        if(i == m) return 0;
        int &ans = dp[i][j];
        if(ans != -1) return ans;
        
        ans = 0;
        if(s[i] == t[j]) ans = go(i + 1, j + 1, s, t);
        ans += go(i + 1, j, s, t);
        return ans;
    }
    
    int numDistinct(string s, string t) {
        m = s.size(), n = t.size();
        memset(dp, -1, sizeof dp);
        return go(0, 0, s, t);
    }
};