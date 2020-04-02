// link to question - https://leetcode.com/problems/number-complement/

class Solution {
public:
    int findComplement(int num) {
        int ans = num;
        
        ans = ans | (ans >> 1);
        ans = ans | (ans >> 2);
        ans = ans | (ans >> 4);
        ans = ans | (ans >> 8);
        ans = ans | (ans >> 16);
        
        ans = ans ^ num;
        return ans;
    }
};