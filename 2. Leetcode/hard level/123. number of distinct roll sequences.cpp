// link to question - https://leetcode.com/problems/number-of-distinct-roll-sequences/

class Solution {
public:
    int dp[10001][7][7];
    bool gcd[7][7];
    int mod = 1e9 + 7;
    
    int go (int i, int first, int second) {
        if (i == 0) return 1;
        int &ans = dp[i][first][second];
        if (ans != -1) return ans;
        
        ans = 0;
        for (int j = 1; j < 7; j++) {
            if (j == first or j == second) continue;
            if (!gcd[j][first]) continue;
            ans = (ans + go (i - 1, j, first)) % mod;
        }
        
        return ans;
    }
    
    int distinctSequences(int n) {
        memset(dp, -1, sizeof dp);
        for (int i = 1; i < 7; i++) {
            gcd[i][0] = true;
            for (int j = 1; j < 7; j++) {
                if (__gcd(i, j) == 1) gcd[i][j] = true;
                else gcd[i][j] = false;
            }
        }
        return go(n, 0, 0);
    }
};