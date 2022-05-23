// link to question - https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/

class Solution {
public:
    int n;
    int dp[1001][2001];
    
    int go (int i, int k, vector<vector<int>>& a) {
        if (i == n or k == 0) return 0;
        int &ans = dp[i][k];
        if (ans != -1) return ans;
        
        ans = 0;
        int len = a[i].size();
        len = min(len, k);
        
        for (int j = 0; j < len; j++) {
            ans = max(ans, a[i][j] + go(i + 1, k - j - 1, a));
        }
        ans = max(ans, go(i + 1, k, a));
        
        return ans;
    }
    
    int maxValueOfCoins(vector<vector<int>>& a, int k) {
        n = a.size();
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < a[i].size(); j++) {
                a[i][j] += a[i][j - 1];
            }
        }
        
        memset(dp, -1, sizeof dp);
        return go(0, k, a);
    }
};