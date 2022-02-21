// link to question - https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> ans;
        if (num % 3 == 0) {
            long long a = num / 3;
            return {a - 1, a, a + 1};
        }
        return ans;
    }
};