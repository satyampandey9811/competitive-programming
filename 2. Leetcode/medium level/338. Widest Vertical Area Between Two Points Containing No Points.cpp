// link to question - https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        int ans = 0, n = a.size(), s = a[0][0];
        
        for(int i = 1; i < n; i++) {
            ans = max(ans, a[i][0] - s);
            s = a[i][0];
        }
        
        return ans;
    }
};