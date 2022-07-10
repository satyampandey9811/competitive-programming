// link to question - https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/

class Solution {
public:
    int fillCups(vector<int>& a) {
        sort(a.rbegin(), a.rend());
        if (a[0] > a[1] + a[2]) return a[0];
        int ans = a[0] + a[1] + a[2] + 1;
        ans /= 2;
        return ans;
    }
};