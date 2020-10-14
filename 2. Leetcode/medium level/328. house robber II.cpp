// link to question - https://leetcode.com/problems/house-robber-ii/

class Solution {
public:        
    int dp[101];
    
    int go(int i, int n, vector<int>& a) {
        if(i >= n) return 0;
        
        int &ans = dp[i];
        if(ans != -1) return ans;
        
        ans = 0;
        ans = go(i + 2, n, a) + a[i];           
        ans = max(ans, go(i + 1, n, a));
        
        return ans;
    }
    
    int rob(vector<int>& a) {       
        int n = a.size();
        if(n == 1) return a[0];
        memset(dp, -1, sizeof dp);
        int ans = go(0, n - 1, a);
        memset(dp, -1, sizeof dp);
        ans = max(ans, go(1, n, a));
        return ans;
    }
};