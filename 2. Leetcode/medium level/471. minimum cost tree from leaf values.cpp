// link to question - https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/

class Solution {
public:
    // important question
    int dp[41][41];
    
    int go(int i, int j, vector<int>& a) {
        if(i == j) return 0;
        
        auto &ans = dp[i][j];
        if(ans != -1) return ans;
        
        ans = INT_MAX;
        
        for(int k = i; k < j; k++) {
            int left = go(i, k, a);
            int right = go(k + 1, j, a);
            
            int maxLeft = 0, maxRight = 0;
            for(int x = i; x <= k; x++)
                maxLeft = max(maxLeft, a[x]);
            for(int x = k + 1; x <= j; x++)
                maxRight = max(maxRight, a[x]);
            
            int sum = left + right + maxLeft * maxRight;
            
            ans = min(ans, sum);
        }
        
        return ans;
    }
    
    int mctFromLeafValues(vector<int>& a) {
        memset(dp, -1, sizeof dp);
        return go(0, a.size() - 1, a);
    }
};