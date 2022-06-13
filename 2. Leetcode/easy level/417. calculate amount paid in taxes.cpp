// link to question - https://leetcode.com/problems/calculate-amount-paid-in-taxes/

class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans = 0, prev = 0;
        
        for (auto &i :brackets) {
            ans += (min(income, i[0]) - prev) * 1.0 * i[1] / 100;
            if (i[0] >= income) break;
            prev = i[0];
        }
        
        return ans;
    }
};