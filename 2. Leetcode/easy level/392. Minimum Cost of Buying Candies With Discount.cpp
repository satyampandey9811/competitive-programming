// link to question - https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/

class Solution {
public:
    int minimumCost(vector<int>& diff) {
        int n = diff.size();
        int ans = 0;
        sort(diff.begin(), diff.end());
        
        for (int i = n - 1; i >= 0;) {
            ans += diff[i];
            if (i - 1 >= 0) ans += diff[i-1];
            i -= 3;
        }
        
        return ans;
    }
};