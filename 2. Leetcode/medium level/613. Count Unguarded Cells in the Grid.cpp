// link to question - https://leetcode.com/problems/count-unguarded-cells-in-the-grid/

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& g, vector<vector<int>>& w) {
        vector<vector<int>> a(m, vector<int>(n));
        vector<vector<int>> b(m, vector<int>(n));
        int r, c;
        
        for (auto &x :w) {
            r = x[0], c = x[1];
            a[r][c] = 5;
            b[r][c] = 5;
        }
        
        for (auto &x :g) {
            r = x[0], c = x[1];
            a[r][c] = 6;
            b[r][c] = 6;
        }
        
        for (auto &x :g) {
            r = x[0], c = x[1];
            
            for (int j = c + 1; j < n; j++) {
                if (a[r][j] > 4) break;
                a[r][j] = 1;
            }
            for (int j = c - 1; j >= 0; j--) {
                if (a[r][j] > 4) break;
                if (a[r][j] == 1) break;
                a[r][j] = 2;
            }
            for (int i = r + 1; i < m; i++) {
                if (b[i][c] > 4) break;
                b[i][c] = 3;
            }
            for (int i = r - 1; i >= 0; i--) {
                if (b[i][c] > 4) break;
                if (b[i][c] == 3) break;
                b[i][c] = 4;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 0 and b[i][j] == 0) ans++;
            }
        }
        
        return ans;
    }
};