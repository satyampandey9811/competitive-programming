// link to question - https://leetcode.com/problems/number-of-zero-filled-subarrays/

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& a) {
        int j = -1, n = a.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                ans += i - j;
            }
            else j = i;
        }
        return ans;
    }
};