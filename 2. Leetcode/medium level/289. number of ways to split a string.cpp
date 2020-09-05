// link to question - https://leetcode.com/problems/number-of-ways-to-split-a-string/

class Solution {
public:
    int numWays(string s) {
        long long int one = 0, n = s.size();
        long long int ans1 = 0, ans2 = 0, mod = 1e9 + 7;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') one++;            
        }
        if(one % 3) return 0;
        one /= 3;        
        
        if(one == 0) return ((n - 2) * (n - 1) / 2) % mod;                
        
        int c = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') c++;
            if(c == one) ans1 = (ans1 + 1) % mod;
            if(c > one) break;
        }
        c = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '1') c++;
            if(c == one) ans2 = (ans2 + 1) % mod;
            if(c > one) break;
        }
        
        return (1LL * ans1 * ans2) % mod;
    }
};