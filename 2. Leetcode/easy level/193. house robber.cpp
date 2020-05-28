// link to question - https://leetcode.com/problems/house-robber/

class Solution {
public:
    int help(vector<int>& a, int i, vector<int>& dp) {
        if(i >= a.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int x = a[i] + help(a, i + 2, dp);
        int y = help(a, i + 1, dp);
        return dp[i] = max(x, y);
    }
    
    int rob(vector<int>& a) {        
        vector<int> dp(a.size() + 1, -1);
        return help(a, 0, dp);
    }
};