// link to question - https://leetcode.com/problems/largest-divisible-subset/

class Solution {
public:
    // important question
    int dp[1001][1001][2];
    int n;
    
    pair<int, int> go(int i, int j, vector<int>& a) {
        if(j >= n) return {0, -1};
        auto &ans = dp[i][j];
        if(ans[0] != -1) return {ans[0], ans[1]};
        
        ans[0] = 0;
        for(int k = j; k < n; k++) {
            if(a[k] % a[i] == 0) {
                auto p = go(k, k + 1, a);
                if(ans[0] < 1 + p.first) {
                    ans[0] = 1 + p.first;
                    ans[1] = k;
                }
            }
        }
        
        return {ans[0], ans[1]};
    }
    
    vector<int> largestDivisibleSubset(vector<int>& a) {
        n = a.size();
        if(n == 1) return a;
        
        memset(dp, -1, sizeof dp);
        sort(a.begin(), a.end());
        
        int ind, val = 0;
        for(int i = 0; i < n - 1; i++) {
            auto res = go(i, i + 1, a);
            if(val < res.first) {
                val = res.first;
                ind = i;
            }
        }
        
        vector<int> ans;
        if(!val) {
            ans.push_back(a[0]);
            return ans;
        }
        
        int c = ind;
        while(c != -1) {
            ans.push_back(a[c]);
            c = dp[c][c+1][1];
        }
        
        return ans;
    }
};