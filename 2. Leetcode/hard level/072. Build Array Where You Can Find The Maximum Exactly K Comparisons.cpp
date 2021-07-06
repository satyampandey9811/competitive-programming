// link to question - https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/

class Solution {
public:
    int dp[51][101][51];
    int mod = 1e9 + 7, t;
    
    int go(int n, int prevMax, int k) {
        if(n == 0) return k == 0;
        if(k > n or k < 0) return 0;
        int &ans = dp[n][prevMax][k];
        if(ans != -1) return ans;
        
        ans = 0;
        
        for(int i = 1; i <= t; i++) {
            if(i <= prevMax) 
                ans = (ans + go(n - 1, prevMax, k)) % mod;
            else ans = (ans + go(n - 1, i, k - 1)) % mod;
        }
        
        return ans;
    }
    
    int numOfArrays(int n, int m, int k) {
        memset(dp, -1, sizeof dp);
        t = m;
        return go(n, 0, k);
    }
};