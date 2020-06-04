// link to question - https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

class Solution {
public:
    int f(string &a, string &b, int i, int j, vector<vector<int>>& dp, vector<int>& aval, vector<int>& bval) {        
        if(i == a.size() and j == b.size()) return 0;
        else if(i == a.size()) return bval[j];                       
        else if(j == b.size()) return aval[i];
        
		if(dp[i][j] != -1) return dp[i][j];
        
        if(a[i] == b[j]) 
            return dp[i][j] = f(a, b, i + 1, j + 1, dp, aval, bval);        
        
        int x = (int)b[j] + f(a, b, i, j + 1, dp, aval, bval);
        int y = (int)a[i] + f(a, b, i + 1, j, dp, aval, bval);                
        
        return dp[i][j] = min(x, y);
    }
    
    int minimumDeleteSum(string a, string b) {
        int m = a.size(), n = b.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        vector<int> aval(m), bval(n);
        int val = 0;
        for(int i = m - 1; i >= 0; i--) {
            val += (int)a[i];
            aval[i] = val;
        }
        val = 0;
        for(int i = n - 1; i >= 0; i--) {
            val += (int)b[i];
            bval[i] = val;
        }
        int ans = f(a, b, 0, 0, dp, aval, bval);
        return ans;
    }
};