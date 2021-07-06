// link to question - https://leetcode.com/problems/palindrome-partitioning-iii/

class Solution {
public:
    int dp[101][101][101];
    
    int go(int i, int j, int k, string& s) {
        int &ans = dp[i][j][k];
        if(ans != -1) return ans;
        
        ans = 0;
        if(k == 1) {
            while(i < j) {
                if(s[i] != s[j]) ans++;
                i++, j--;
            }
            return ans;
        }
        
        ans = INT_MAX;
        for(int l = i; l <= j - k + 1; l++) {
            int t = go(i, l, 1, s) + go(l + 1, j, k - 1, s);
            ans = min(ans, t);
        }
        
        return ans;
    }
    
    int palindromePartition(string s, int k) {
        int n = s.size();
        memset(dp, -1, sizeof dp);
        return go(0, n - 1, k, s);
    }
};