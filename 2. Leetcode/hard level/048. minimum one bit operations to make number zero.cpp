// link to question - https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/

class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans = 0;
        int c = 1;
        
        while(n > 0) {
            int x = 32 - __builtin_clz(n);
            if(c) {
                ans += pow(2, x) - 1;
                c = 0;
            }
            else {
                ans = ans - pow(2, x) + 1;
                c = 1;
            }
            n ^= 1 << (x - 1);
        }
        
        return ans;
    }
};