// link to question - https://leetcode.com/problems/number-of-1-bits/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        for(int i = 0; i < 33; i++){
            if(n & (1LL << i)) ans++;
        }
        return ans;
    }
};