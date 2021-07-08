// link to question - https://leetcode.com/problems/palindrome-partitioning-ii/

class Solution {
public:
    // important question
    int n;
    vector<vector<bool>> pa;
    vector<int> dp;
    
    int go(int i, string& s) {
        if(i == n) return -1;
        int &ans = dp[i];
        if(ans != -1) return ans;
        
        ans = n;
        for(int j = i; j < n; j++) {
            if(pa[i][j]) {
                ans = min(ans, go(j + 1, s));
            }
        }
        
        return ++ans;
    }
    
    int minCut(string s) {
        n = s.size();
        pa.resize(n + 1, vector<bool>(n + 1, false));
        dp.resize(n + 1, -1);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                if(s[i] == s[j]) {
                    pa[j][i] = (i-j > 2) ? pa[j+1][i-1] : 1;
                }
            }
        }
        
        return go(0, s);
    }
};