// link to question - https://leetcode.com/problems/domino-and-tromino-tiling/

class Solution {
public:
    int numTilings(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int a[2][n];
        a[0][0] = 1;
        a[0][1] = 2, a[1][1] = 1;
        int mod = 1e9 + 7;
        
        for (int i = 2; i < n; i++) {
            a[0][i] = ((a[0][i-1] % mod + a[0][i-2] % mod) % mod + 2 * a[1][i-1] % mod) % mod;
            a[1][i] = (a[1][i-1] % mod + a[0][i-2] % mod) % mod;
        }
        
        return a[0][n-1];
    }
};