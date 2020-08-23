// link to question - https://leetcode.com/problems/maximum-number-of-coins-you-can-get/

class Solution {
public:
    int maxCoins(vector<int>& a) {
        sort(a.begin(), a.end());
        int ans = 0, c = 0;
        for(int i = a.size() - 2; i > c; i -= 2) {
            ans += a[i];
            c++;
        }
        return ans;
    }
};