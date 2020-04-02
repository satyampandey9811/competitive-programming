// link to question - https://leetcode.com/problems/binary-number-with-alternating-bits/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long a = n;
        a = a ^ (a >> 1);
        return !(a & (a + 1));
    }
};