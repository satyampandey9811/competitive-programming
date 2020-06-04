// link to question - https://leetcode.com/problems/delete-operation-for-two-strings/

class Solution {
public:        
    int dp[501][501];
    
    int help(string &a, string &b, int i, int j) {        
        if(i == a.size() and j == b.size()) return 0;
        if(i == a.size()) return b.size() - j;
        if(j == b.size()) return a.size() - i;
        
        int &ans = dp[i][j];
        if(ans != -1) return ans;
        
        if(a[i] == b[j]) return ans = help(a, b, i + 1, j + 1);
        return ans = 1 + min(help(a, b, i, j + 1), help(a, b, i + 1, j));
    }
    
    int minDistance(string a, string b) {
        int m = a.size(), n = b.size();              
        memset(dp, -1, sizeof dp);
        return help(a, b, 0, 0);
    }
};