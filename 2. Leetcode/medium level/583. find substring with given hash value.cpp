 // link to question - https://leetcode.com/problems/find-substring-with-given-hash-value/

 class Solution {
public:    
    string subStrHash(string s, int p, int mod, int k, int h) {
        int n = s.size();
        long long a = 0, pk = 1;
        int j = n - 1, pot;
        
        for (int i = n - 1; i > n - k; i--) {
            a = (a * p + s[i] - 'a' + 1) % mod;
            pk = pk * p % mod;
        }
        
        for (int i = n - k; i >= 0; i--) {
            a = (a * p + s[i] - 'a' + 1) % mod;
            if (a == h) pot = i;
            a = (a - ((s[j] - 'a' + 1) * pk % mod) + mod) % mod;
            j--;
        }
        
        return s.substr(pot, k);
    }
};