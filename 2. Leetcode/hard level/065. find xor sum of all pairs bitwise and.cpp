// link to question - https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/

class Solution {
public:
    int getXORSum(vector<int>& a, vector<int>& b) {
        int ans = 0, x = 0;
        for(int &i: b) x ^= i;
        for(int i = 0; i < a.size(); i++) {
            ans ^= a[i] & x;
        }
        return ans;
    }
};