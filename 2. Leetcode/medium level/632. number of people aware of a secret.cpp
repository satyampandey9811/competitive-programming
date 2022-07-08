// link to question - https://leetcode.com/problems/number-of-people-aware-of-a-secret/

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int ans = 0, f = 0;
        int mod = 1e9 + 7;
        
        vector<int> a(n + 1);
        a[1] = 1;
        
        for (int i = 1; i < n; i++) {
            for (int j = i + delay; j <= min(n, i + forget - 1); j++) {
                a[j] = (a[i] + a[j]) % mod;
            }
            
            if (i + forget <= n) {
                f = (a[i] + f) % mod;
            }
        }
        
        
        for (int i = 1; i <= n; i++) {
            ans = (a[i] + ans) % mod;
        }
        
        ans = (ans - f + mod) % mod;
        
        return ans;
    }
};