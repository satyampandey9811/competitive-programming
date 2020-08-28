// link to question - https://leetcode.com/problems/constrained-subsequence-sum/

class Solution {
public:    
    int constrainedSubsetSum(vector<int>& a, int k) {        
        int n = a.size();
        vector<int> dp(n);
        multiset<int> window = {0};
        
        for(int i = 0; i < n; i++) {
            dp[i] = a[i] + *window.rbegin();
            window.insert(dp[i]);
            if(i >= k) window.erase(window.find(dp[i - k]));
        }
        return *max_element(dp.begin(), dp.end());
    }
};