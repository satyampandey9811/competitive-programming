// link to question - https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution {
public:
    int countSquares(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();        
        int ans = 0;
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(a[i][j] == 1) {
                    a[i][j] = 1 + min({a[i-1][j-1], a[i-1][j], a[i][j-1]});
                }
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans += a[i][j];
            }
        }
        
        return ans;
    }
};