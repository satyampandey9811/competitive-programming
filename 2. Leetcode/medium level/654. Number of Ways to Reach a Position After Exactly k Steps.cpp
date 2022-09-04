// link to question - https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/

class Solution {
public:
    int dp[3002][1001][2];
    int mod = 1e9 + 7;
    
    int go (int prev, int curr, int end, int k) {
        if (k == 0 and curr == end) return 1;
        if (k == 0) return 0;
        if (abs(end - curr) > k) return 0;
        int v = curr - prev;
        if (v == -1) v = 0;
        
        int &ans = dp[curr][k][v];
        if (ans != -1) return ans;
        
        ans = go (curr, curr + 1, end, k - 1);
        ans = (ans + go (curr, curr - 1, end, k - 1)) % mod;
        
        return ans;
    }
    
    int numberOfWays(int s, int e, int k) {
        int d = abs(e - s);
        if ((d & 1) and k % 2 == 0) return 0;
        if (d % 2 == 0 and (k & 1)) return 0;
        
        s += 1000;
        e += 1000;
        memset(dp, -1, sizeof dp);
        
        int ans = go (s, s + 1, e, k - 1);
        ans = (ans + go (s, s - 1, e, k - 1)) % mod;
        return ans;
    }
};