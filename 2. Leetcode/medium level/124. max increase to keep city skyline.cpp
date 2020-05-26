// link to question - https://leetcode.com/problems/max-increase-to-keep-city-skyline/

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& a) {
        int n = a.size(), ans = 0;
        vector<int> r(n), c(n);
        for(int i = 0; i < n; i++) {
            int maxrval = INT_MIN;
            int maxcval = INT_MIN;
            for(int j = 0; j < n; j++) {
                maxrval = max(maxrval, a[i][j]);
                maxcval = max(maxcval, a[j][i]);
            }
            r[i] = maxrval;
            c[i] = maxcval;
        }         
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans += max(0, min(r[i], c[j]) - a[i][j]);
            }
        }
        return ans;
    }
};