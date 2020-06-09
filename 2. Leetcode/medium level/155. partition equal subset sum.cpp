// link to question - https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return 0;
        sum /= 2;
        int n = nums.size();
        bool dp[n + 1][sum + 1];
        
        for(int i = 0; i <= n; i++) dp[i][0] = true;
        for(int i = 1; i <= sum; i++) dp[0][i] = false;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= sum; j++) {
                if(nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] or dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[n][sum];
    }
};