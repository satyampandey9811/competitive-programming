// link to question - https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/

class Solution {
public:
    int countPaths(vector<vector<int>>& a) {
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int mod = 1e9 + 7;
        int m = a.size(), n = a[0].size();
        vector<array<int, 3>> small(m * n);
        int ct = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                small[ct][0] = a[i][j];
                small[ct][1] = i;
                small[ct++][2] = j;
            }
        }
        
        sort (small.begin(), small.end(), 
              [](array<int, 3>& x, array<int, 3>& y) {
                  return x[0] < y[0];
              }    
        );
        
        vector<vector<int>> val(m, vector<int>(n));
        
        int r, c, nr, nc;
        int len = small.size();
        
        for (int i = 0; i < len; i++) {
            c = small[i][2];
            r = small[i][1];
            
            for (int j = 0; j < 4; j++) {
                nc = c + dir[j][1];
                nr = r + dir[j][0];
                
                if (nr < 0 or nc < 0 or nr >= m or nc >= n) {
                    continue;
                }
                if (a[r][c] < a[nr][nc]) {
                    val[nr][nc] = (val[nr][nc] + val[r][c] + 1) % mod;
                }
            }
        }
        
        int res = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = (res + val[i][j]) % mod;
            }
        }
        res = (res + len) % mod;
        
        return res;
    }
};