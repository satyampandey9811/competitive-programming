// link to question - https://leetcode.com/problems/single-number-ii/

class Solution {
public:
    int singleNumber(vector<int>& a) {
        ios::sync_with_stdio(false), cin.tie(0);
        int ones = 0, twos = 0, mask = 0;
        for(int i: a) {
            twos |= ones & i;
            ones ^= i;
            mask = ~(ones & twos);
            ones &= mask;
            twos &= mask;
        }
        return ones;
    }
};