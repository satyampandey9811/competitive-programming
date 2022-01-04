// link to question - https://leetcode.com/problems/remove-boxes/

class Solution {
public:
    int dp[101][101][101];
    
    int go (int l, int r, int k, vector<int>& a) {
        if (l > r) return 0;
        
        int &ans = dp[l][r][k];
        if (ans != -1) return ans;
        
        while (l + 1 <= r and a[l + 1] == a[l]) {
            l++, k++;
        }
        ans = (k + 1) * (k + 1) + go(l + 1, r, 0, a);
        
        for (int i = l + 1; i <= r; i++) {
            if (a[i] == a[l]) {
                ans = max(ans, go(i, r, k + 1, a) + go(l + 1, i - 1, 0, a));
            }
        }
        
        return ans;
    }
    
    int removeBoxes(vector<int>& a) {
        memset(dp, -1, sizeof dp);
        return go(0, a.size() - 1, 0, a);
    }
};