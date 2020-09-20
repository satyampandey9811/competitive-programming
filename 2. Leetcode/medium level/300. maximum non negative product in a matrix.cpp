// link to question - https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/

class Solution {
public:
    int mod = 1e9 + 7;
    
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();    
        
        vector<vector<long long>> a(m, vector<long long>(n)), b = a;
                                    
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                a[i][j] = b[i][j] = grid[i][j];
            }
        }                                    
        
        for(int i = n - 2; i >= 0; i--) {
            a[m-1][i] *= a[m-1][i+1];
            b[m-1][i] *= a[m-1][i+1];
        }
        
        for(int i = m - 2; i >= 0; i--) {
            a[i][n-1] *= a[i+1][n-1];
            b[i][n-1] *= a[i+1][n-1];
        }
        
        for(int i = m - 2; i >= 0; i--) {
            for(int j = n - 2; j >= 0; j--) {                
                
                int x = a[i][j], y = b[i][j];
                if(x == 0) continue;                
                b[i][j] = max(y * b[i][j+1], y * b[i+1][j]);
                b[i][j] = max({b[i][j], x * a[i][j+1], x * a[i+1][j]});
                a[i][j] = min(x * a[i][j+1], x * a[i+1][j]);
                a[i][j] = min({a[i][j], y * b[i][j+1], y * b[i+1][j]});
            }
        }

        if(b[0][0] < 0) return -1;
        else return b[0][0] % mod;
    }
};