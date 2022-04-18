// link to question - https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path/

class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();
        vector<vector<int>> two(m, vector<int>(n));
        vector<vector<int>> five(m, vector<int>(n));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                while (a[i][j] % 5 == 0) {
                    five[i][j]++;
                    a[i][j] /= 5;
                }
                while (a[i][j] % 2 == 0) {
                    two[i][j]++;
                    a[i][j] /= 2;
                }
            }
        }
        
        vector<vector<int>> twoleft = two;
        vector<vector<int>> tworight = two;
        vector<vector<int>> twoup = two;
        vector<vector<int>> twodown = two;
        vector<vector<int>> fiveleft = five;
        vector<vector<int>> fiveright = five;
        vector<vector<int>> fiveup = five;
        vector<vector<int>> fivedown = five;
        
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                twoleft[i][j] += twoleft[i][j - 1];
                fiveleft[i][j] += fiveleft[i][j - 1];
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = n - 2; j >= 0; j--) {
                tworight[i][j] += tworight[i][j + 1];
                fiveright[i][j] += fiveright[i][j + 1];
            }
        }
        
        for (int j = 0; j < n; j++) {
            for (int i = 1; i < m; i++) {
                twoup[i][j] += twoup[i - 1][j];
                fiveup[i][j] += fiveup[i - 1][j];
            }
        }
        
        for (int j = 0; j < n; j++) {
            for (int i = m - 2; i >= 0; i--) {
                twodown[i][j] += twodown[i + 1][j];
                fivedown[i][j] += fivedown[i + 1][j];
            }
        }
        
        int ans = 0, val;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) {
                    val = min(twoleft[i][j] + twoup[i - 1][j], fiveleft[i][j] + fiveup[i - 1][j]);
                    ans = max(ans, val);
                    
                    val = min(tworight[i][j] + twoup[i - 1][j], fiveright[i][j] + fiveup[i - 1][j]);
                    ans = max(ans, val);
                }
                
                if (i < m - 1) {
                    val = min(twoleft[i][j] + twodown[i + 1][j], fiveleft[i][j] + fivedown[i + 1][j]);
                    ans = max(ans, val);
                
                    val = min(tworight[i][j] + twodown[i + 1][j], fiveright[i][j] + fivedown[i + 1][j]);
                    ans = max(ans, val);
                }
            }
        }
        
        ans = max(ans, min(twoleft[0][n - 1], fiveleft[0][n - 1]));
        
        return ans;
    }
};