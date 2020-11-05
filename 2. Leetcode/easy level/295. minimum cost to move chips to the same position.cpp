// link to question - https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/

class Solution {
public:
    int minCostToMoveChips(vector<int>& a) {
        int ans = INT_MAX, n = a.size(), x, c;
        for(int i = 0; i < n; i++) {
            x = a[i], c = 0;
            for(int j = 0; j < n; j++) {
                if(abs(a[i] - a[j] & 1)) c++;
            }
            ans = min(ans, c);
        }
        return ans;
    }
};