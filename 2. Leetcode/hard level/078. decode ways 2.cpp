// link to question - https://leetcode.com/problems/decode-ways-ii/

class Solution {
public:
    int mod = 1e9 + 7, n;
    vector<int> dp;
    
    int go(int i, string& s) {
        if(i >= n) return 1;
        if(s[i] == '0') return 0;
        
        int &ans = dp[i];
        if(ans != -1) return ans;
        
        int f = go(i + 1, s) % mod;
        int g = go(i + 2, s) % mod;
        
        ans = f;
        
        if(s[i] == '1') {
            if(i + 1 < n) {
                if(s[i+1] == '*') ans = (ans + g * 1LL * 9 % mod) % mod;
                else ans = (ans + g) % mod;
            }
        }
        else if(s[i] == '2') {
            if(i + 1 < n) {
                if(s[i+1] == '*') ans = (ans + g * 1LL * 6 % mod) % mod;
                else if(s[i+1] < '7') ans = (ans + g) % mod;
            }
        }
        else if(s[i] == '*') {
            ans = (ans + f * 1LL * 8 % mod) % mod;
            if(i + 1 < n) {
                if(s[i+1] == '*') ans = (ans + g * 1LL * 15 % mod) % mod;
                else if(s[i+1] < '7') ans = (ans + g * 1LL * 2 % mod) % mod;
                else ans = (ans + g) % mod;
            }
        }
        
        return ans;
    }
    
    int numDecodings(string s) {
        n = s.size();
        dp.resize(n + 1, -1);
        return go(0, s);
    }
};