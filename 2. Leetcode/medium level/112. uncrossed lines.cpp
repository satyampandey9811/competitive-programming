// link to question - https://leetcode.com/problems/uncrossed-lines/

class Solution {
public:
    int help(vector<int>& a, vector<int>& b, int i, int j, vector<vector<int>>& dp) {
        if(i == a.size() or j == b.size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(a[i] == b[j]) {
            dp[i+1][j+1] = help(a, b, i + 1, j + 1, dp);
            return 1 + dp[i+1][j+1];
        }
        int x = help(a, b, i, j + 1, dp);
        int y = help(a, b, i + 1, j, dp);
        return dp[i][j] = max(x, y);
    }
    
    int maxUncrossedLines(vector<int>& a, vector<int>& b) {
        int m = a.size(), n = b.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return help(a, b, 0, 0, dp);
    }
};