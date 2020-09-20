// link to question - https://leetcode.com/problems/unique-paths-iii/

class Solution {
public:
    int m, n;
    vector<vector<int>> a;
    vector<vector<bool>> vis;
    int ans;
    
    void go(int i, int j, int& ex, int& ey) {
        if(i < 0 or j < 0 or i == m or j == n or a[i][j] == -1 or vis[i][j]) return;        
        
        if(i == ex and j == ey) {
            for(int r = 0; r < m; r++) {
                for(int c = 0; c < n; c++) {
                    if(a[r][c] == 0 and !vis[r][c]) {                        
                        return;
                    }
                }
            }
            ans++;
            return;
        }
        
        vis[i][j] = true;
        
        go(i - 1, j, ex, ey);
        go(i + 1, j, ex, ey);
        go(i, j - 1, ex, ey);
        go(i, j + 1, ex, ey);
        
        vis[i][j] = false;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        a = grid;
        ans = 0;
        vis.resize(m, vector<bool>(n, false));
        
        int sx, sy, ex, ey;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(a[i][j] == 1) sx = i, sy = j;
                else if(a[i][j] == 2) ex = i, ey = j;
            }
        }
        
        go(sx, sy, ex, ey);
        
        return ans;
    }
};