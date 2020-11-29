// link to question - https://leetcode.com/problems/richest-customer-wealth/

class Solution {
public:
    int maximumWealth(vector<vector<int>>& a) {
        int ans = 0;
        for(int i = 0; i < a.size(); i++) {
            int sum = 0;
            sum = accumulate(a[i].begin(), a[i].end(), 0);
            ans = max(ans, sum);
        }
        
        return ans;
    }
};