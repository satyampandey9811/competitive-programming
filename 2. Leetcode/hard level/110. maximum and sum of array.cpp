// link to question - https://leetcode.com/problems/maximum-and-sum-of-array/

class Solution {
public:
    int dp[18][512][512];
    int n, s;
    
    int go (int i, int first, int second, vector<int>& a) {
        if (i == n) return 0;
        int &ans = dp[i][first][second];
        if (ans != -1) return ans;
        
        ans = 0;
        
        for (int j = 0; j < s; j++) {
            if ((1 & (first >> j)) and (1 & (second >> j))) continue;
            if (1 & (first >> j)) {
                ans = max(ans, (a[i] & (j + 1)) + go(i + 1, first, second + (1 << j), a));
            }
            else {
                ans = max(ans, (a[i] & (j + 1)) + go(i + 1, first + (1 << j), second, a));
            }
        }
        
        return ans;
    }
    
    int maximumANDSum(vector<int>& a, int slot) {
        n = a.size();
        memset(dp, -1, sizeof dp);
        s = slot;
        return go(0, 0, 0, a);
    }
};