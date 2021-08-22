// link to question: https://leetcode.com/problems/find-greatest-common-divisor-of-array/

class Solution {
public:
    int findGCD(vector<int>& a) {
        sort(a.begin(), a.end());
        int ans = __gcd(a[0], a.back());
        return ans;
    }
};