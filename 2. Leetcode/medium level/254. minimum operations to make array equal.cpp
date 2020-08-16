// link to question - https://leetcode.com/problems/minimum-operations-to-make-array-equal/

class Solution {
public:
    int minOperations(int n) {
        int ans = 0, c = 0;
        if(n & 1) c = n / 2 * 2 + 1;
        else c = (n - 1) / 2 * 2 + 2;
        for(int i = 1; i <= c; i += 2) {
            ans += c - i;
        }
        return ans;
    }
};