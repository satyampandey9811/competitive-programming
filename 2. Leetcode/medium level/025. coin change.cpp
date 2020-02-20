// link to question - https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& a, int t) {        
        int n = a.size();
        vector<int> dp(t + 1, t + 1);        
        dp[0] = 0;
        for(int i = 1; i <= t; i++){
            for(int j = 0; j < n; j++){                                           
                if(i >= a[j])
                    dp[i] = min(dp[i], dp[i-a[j]] + 1);
            }
        }
        return dp[t] > t ? -1 : dp[t];
    }
};