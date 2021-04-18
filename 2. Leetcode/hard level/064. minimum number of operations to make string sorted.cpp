// link to question - https://leetcode.com/problems/minimum-number-of-operations-to-make-string-sorted/

class Solution {
public:
    int mod = 1e9 + 7;
    
    int power(int a, int b, int modulo) {
        int ans = 1;
        while(b > 0) {
            if(b & 1) ans = (1LL * ans * a) % modulo;
            b >>= 1;
            a = (1LL * a * a) % modulo;
        }
        return ans;
    }
    
    int makeStringSorted(string s) {
        int ans = 0, n = s.size();
        
        vector<long long> fact(n + 1), ifact(n + 1);
        fact[0] = ifact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * 1LL * i) % mod;
            ifact[i] = power(fact[i], mod - 2, mod);
        }
        
        for(int i = 0; i < n; i++) {
            int c = 0;
            vector<int> d(26);
            for(int j = i; j < n; j++) {
                if(s[j] < s[i]) c++;
                d[s[j] - 'a']++;
            }
            int val = fact[n - i - 1] * c % mod;
            
            for(int j = 0; j < 26; j++) {
                if(d[j] > 1) {
                    val = val * ifact[d[j]] % mod;
                }
            }
            
            ans = (ans + val) % mod;
        }
        
        return ans % mod;
    }
};