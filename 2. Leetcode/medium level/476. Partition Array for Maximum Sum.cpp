// link to question - https://leetcode.com/problems/partition-array-for-maximum-sum/

class Solution {
public:
    vector<int> dp;
    int n;
    
    int go(int i, int& k, vector<int>& a) {
        if(i == n) return 0;
        int &ans = dp[i];
        if(ans != -1) return ans;
        
        ans = 0;
        int val = 0, sum;
        for(int it = i; it <= min(n - 1, i + k - 1); it++) {
            val = max(val, a[it]);
            sum = val * (it - i + 1);
            ans = max(ans, sum + go(it + 1, k, a));
        }
        
        return ans;
    }

    int maxSumAfterPartitioning(vector<int>& a, int k) {
        n = a.size();
        dp.resize(n + 1, -1);
        return go(0, k, a);
    }
};