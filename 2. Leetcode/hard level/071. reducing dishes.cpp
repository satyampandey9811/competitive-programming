// link to question - https://leetcode.com/problems/reducing-dishes/

class Solution {
public:
    int dp[501][501];
    int n;
    
    int go(int t, int i, vector<int>& a) {
        if(i == n) return 0;
        int &ans = dp[t][i];
        if(ans != -1) return ans;
        
        ans = t * a[i] + go(t + 1, i + 1, a);
        ans = max(ans, go(t, i + 1, a));
        return ans;
    }
    
    int maxSatisfaction(vector<int>& a) {
        sort(a.begin(), a.end());
        memset(dp, -1, sizeof dp);
        n = a.size();
        return go(1, 0, a);
    }
};