// link to question - https://leetcode.com/problems/count-good-numbers/

class Solution {
public:
    int mod = 1e9 + 7;
    
    int power(int a, long long b) {
        int ans = 1;
        while(b > 0) {
            if(b & 1) ans = (ans * 1LL * a) % mod;
            b /= 2;
            a = (a * 1LL * a) % mod;
        }
        return ans;
    }
    
    int countGoodNumbers(long long n) {
        int e = power(5, (n + 1) / 2);    
        int p;
        p = power(4, n / 2);
        
        int ans = (e * 1LL * p) % mod;
        return ans;
    }
};