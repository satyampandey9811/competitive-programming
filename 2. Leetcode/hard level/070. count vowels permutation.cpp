// link to question - https://leetcode.com/problems/count-vowels-permutation/

class Solution {
public:
    vector<vector<int>> dp;
    int mod = 1e9 + 7;
    
    int go(int i, int j, int& n) {
        if(j == n - 1) return 1;
        int &ans = dp[i][j];
        if(ans != -1) return ans;
        
        ans = 0;
        if(i == 0) ans = (ans + go(1, j + 1, n)) % mod;
        else if(i == 1) {
            ans = (ans + go(0, j + 1, n)) % mod;
            ans = (ans + go(2, j + 1, n)) % mod;
        }
        else if(i == 2) {
            ans = (ans + go(0, j + 1, n)) % mod;
            ans = (ans + go(1, j + 1, n)) % mod;
            ans = (ans + go(3, j + 1, n)) % mod;
            ans = (ans + go(4, j + 1, n)) % mod;
        }
        else if(i == 3) {
            ans = (ans + go(2, j + 1, n)) % mod;
            ans = (ans + go(4, j + 1, n)) % mod;
        }
        else ans = (ans + go(0, j + 1, n)) % mod;
        
        return ans;
    }
    
    int countVowelPermutation(int n) {
        dp.resize(5, vector<int>(n + 1, -1));
        int ans = 0;
        for(int i = 0; i < 5; i++) {
            ans = (ans + go(i, 0, n)) % mod;
        }
        return ans;
    }
};