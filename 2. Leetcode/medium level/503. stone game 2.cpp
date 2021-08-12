// link to question - https://leetcode.com/problems/stone-game-ii/

class Solution {
public:
    // important question
    int n;
    int dp[101][500];
    int sum[102];
    
    int go(int i, int m, vector<int>& a) {
        if(i >= n) return 0;
        if(i + 2 * m >= n) return sum[i];
        int &ans = dp[i][m];
        if(ans != -1) return ans;
        
        int res = INT_MAX;
        
        for(int j = 1; j <= 2 * m; j++) {
            res = min(res, go(i + j, max(m, j), a));
        }
        
        return ans = sum[i] - res;
    }
    
    int stoneGameII(vector<int>& a) {
        n = a.size();
        sum[n] = 0;
        for(int i = n-1; i >= 0; i--) {
            sum[i] = a[i] + sum[i+1];
        }
        memset(dp, -1, sizeof dp);
        return go(0, 1, a);
    }
};