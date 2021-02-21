// link to question - https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/

class Solution {
public:
    int m, n;
    int dp[1001][1001];
    
    int go(vector<int>& a, vector<int>& b, int i, int j, int k) {
        if(k == n) return 0;
        int &ans = dp[i][m-j];
        if(ans != -1) return ans;                
        
        ans = a[i] * b[k] + go(a, b, i + 1, j, k + 1);
        ans = max(ans, a[j] * b[k] + go(a, b, i, j - 1, k + 1));
        
        return ans;
    }
    
    int maximumScore(vector<int>& a, vector<int>& b) {
        m = a.size(), n = b.size();        
        memset(dp, -1, sizeof dp);
        return go(a, b, 0, m - 1, 0);
    }
};