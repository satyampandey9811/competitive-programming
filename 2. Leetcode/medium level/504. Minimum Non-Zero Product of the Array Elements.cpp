// link to question - https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements/

class Solution {
public:
    long long power(long long a, long long b, int mod) {
        long long ans = 1;
        a %= mod;
        while(b) {
            if(b & 1) ans = ans * a % mod;
            b >>= 1;
            a = a * a % mod;
        }
        return ans;
    }
    
    int minNonZeroProduct(int p) {
        if(p == 1) return 1;
        long long a = (1LL << p) - 1;
        int mod = 1e9 + 7;
        
        long long b = power(a - 1, a / 2, mod);
        a = a % mod * b % mod;
        return a;
    }
};