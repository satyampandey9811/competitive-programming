// link to question - https://leetcode.com/problems/max-dot-product-of-two-subsequences/

class Solution {
public:
    long long int helper(vector<int>& a, vector<int>& b, int i, int j, vector<vector<long long int>> &dp) {
        if(i == a.size() or j == b.size()) 
            return -1e4;
        if(dp[i][j] != INT_MIN) return dp[i][j];
        long long int w = a[i] * b[j] + max(0LL, helper(a, b, i + 1, j + 1, dp));
        long long int x = helper(a, b, i, j + 1, dp);
        long long int y = helper(a, b, i + 1, j, dp);
        long long int z = helper(a, b, i + 1, j + 1, dp);
        
        return dp[i][j] = max({w, x, y, z});
    }
    
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        vector<vector<long long int>> dp(a.size() + 1, vector<long long int>(b.size() + 1, INT_MIN));
        return helper(a, b, 0, 0, dp);
    }
};