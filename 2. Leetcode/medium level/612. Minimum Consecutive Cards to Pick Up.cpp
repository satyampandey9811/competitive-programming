// link to question - https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/

class Solution {
public:
    int minimumCardPickup(vector<int>& a) {
        int n = a.size();
        vector<int> b(1e6 + 10, -1);
        int ans = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            if (b[a[i]] == -1) b[a[i]] = i;
            else {
                ans = min(ans, i - b[a[i]] + 1);
                b[a[i]] = i;
            }
        }
        
        if (ans == INT_MAX) return -1;
        return ans;
    }
};