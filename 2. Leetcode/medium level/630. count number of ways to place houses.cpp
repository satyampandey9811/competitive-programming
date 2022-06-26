// link to question - https://leetcode.com/problems/count-number-of-ways-to-place-houses/

class Solution {
public:
    int dp[10001][2][2];
    int mod = 1e9 + 7;
    
    int go (int i, int pt, int pb, int &n) {
        if (i == n) return 1;
        int &ans = dp[i][pt][pb];
        if (ans != -1) return ans;
        
        ans = go(i + 1, 0, 0, n);
        if (!pt) ans = (ans + go(i + 1, 1, 0, n)) % mod;
        if (!pb) ans = (ans + go(i + 1, 0, 1, n)) % mod;
        if (!pt and !pb) ans = (ans + go(i + 1, 1, 1, n)) % mod;
        
        return ans % mod;
    }
    
    int countHousePlacements(int n) {
        memset(dp, -1, sizeof dp);
        return go(0, 0, 0, n);
    }
};