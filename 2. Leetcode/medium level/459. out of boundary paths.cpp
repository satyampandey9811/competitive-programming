// link to question - https://leetcode.com/problems/out-of-boundary-paths/

class Solution {
public:
    // important question
    int dp[51][51][51];
    int mod = 1e9 + 7;
    
    int go(int i, int j, int c, int &m, int &n, int &mv) {
        if(i < 0 or j < 0 or i == m or j == n) return 1;
        if(c == mv) return 0;
        
        int &ans = dp[i][j][c];
        if(ans != -1) return ans;
        
        ans = 0;
        ans = (ans + go(i + 1, j, c + 1, m, n, mv)) % mod;
        ans = (ans + go(i - 1, j, c + 1, m, n, mv)) % mod;
        ans = (ans + go(i, j + 1, c + 1, m, n, mv)) % mod;
        ans = (ans + go(i, j - 1, c + 1, m, n, mv)) % mod;
        return ans;
    }
    
    int findPaths(int m, int n, int mv, int r, int c) {
        memset(dp, -1, sizeof dp);
        return go(r, c, 0, m, n, mv);
    }
};