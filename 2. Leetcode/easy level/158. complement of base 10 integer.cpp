// link to question - https://leetcode.com/problems/complement-of-base-10-integer/

class Solution {
public:
    int bitwiseComplement(int num) {
        if(!num) return 1;
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