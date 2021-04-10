// link to question - https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

class Solution {
public:
    int m, n, ans;
    vector<vector<int>> dp;
    
    int go(int len, int val, int i, int j, vector<vector<int>>& a) {
        if(i < 0 or i == m or j < 0 or j == n) return 0;
        if(a[i][j] <= val) return 0;
        if(dp[i][j]) return dp[i][j];
        
        int w = go(len + 1, a[i][j], i - 1, j, a);
        int x = go(len + 1, a[i][j], i + 1, j, a);
        int y = go(len + 1, a[i][j], i, j - 1, a);
        int z = go(len + 1, a[i][j], i, j + 1, a);
        
        return dp[i][j] = max({w, x, y, z}) + 1;
    }
    
    int longestIncreasingPath(vector<vector<int>>& a) {
        m = a.size(), n = a[0].size(), ans = 1;
        dp.resize(m, vector<int>(n));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans = max(ans, go(0, -1, i, j, a));
            }
        }
        
        return ans;
    }
};