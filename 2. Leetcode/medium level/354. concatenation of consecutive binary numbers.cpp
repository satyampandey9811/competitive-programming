// link to question - https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/

class Solution {
public:
    int find(int n) {
        int len = 0;
        while(n) {
            len++;
            n /= 2;
        }
        return len;
    }
    
    int concatenatedBinary(int n) {
        long long int ans = 0, mod = 1e9 + 7;
        for(int i = 1; i <= n; i++) {
            int len = find(i);
            ans = ((ans << len) + i) % mod;            
        }
        return ans % mod;
    }
};