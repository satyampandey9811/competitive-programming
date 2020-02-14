// link to question - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& a) {
        if(a.empty()) return 0;
        int small = a[0];
        int ans = 0;
        for (int i = 1;i < a.size();i++) {
            small = min(small, a[i]);
            ans = max(ans, a[i] - small);
        }    
        return ans;
    }
};