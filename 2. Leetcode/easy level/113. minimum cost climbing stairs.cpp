// link to question - https://leetcode.com/problems/min-cost-climbing-stairs/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n);
        dp[0] = a[0], dp[1] = a[1];
        for(int i = 2; i < n; i++)
            dp[i] = min(dp[i-1] + a[i], dp[i-2] + a[i]);
        return min(dp[n-2], dp[n-1]);
    }
};