// link to question - https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/

class Solution {
public:
    int countOdds(int low, int high) {
        int ans = (high + 1) / 2 - low / 2;
        return ans;
    }
};