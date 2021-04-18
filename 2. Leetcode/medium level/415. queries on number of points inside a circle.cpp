// link to question - https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& b, vector<vector<int>>& a) {
        int m = a.size(), n = b.size();
        vector<int> ans(m);
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int x = pow(b[j][0] - a[i][0], 2) + pow(b[j][1] - a[i][1], 2) - pow(a[i][2], 2);
                if(x <= 0) ans[i]++;
            }
        }
        
        return ans;
    }
};