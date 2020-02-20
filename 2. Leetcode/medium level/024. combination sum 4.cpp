// link to question - https://leetcode.com/problems/combination-sum-iv/

class Solution {
public:
    int combinationSum4(vector<int>& a, int t) {
        int n = a.size();
        vector<unsigned int> dp(t + 1);
        dp[0] = 1;
        for(int i = 1; i <= t; i++){
            for(auto x: a){
                if(i >= x)
                    dp[i] += dp[i - x];                                    
            }
        }
        return dp[t];
    }
};