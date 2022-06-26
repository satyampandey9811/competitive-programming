// link to question - https://leetcode.com/problems/maximum-xor-after-operations/

class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int ans = 0;
        for (auto &i :nums) ans |= i;
        return ans;
    }
};