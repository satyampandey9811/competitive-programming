// link to question - https://leetcode.com/problems/max-area-of-island/

class Solution {
public:
    int m, n, ans, area;
    
    void dfs(vector<vector<int>>&grid, vector<vector<bool>>&vis, int i, int j) {
        if(i < 0 or j < 0 or i == m or j == n) return;
        if(vis[i][j] or grid[i][j] == 0) return;
        vis[i][j] = true;
        area++;
        ans = max(ans, area);
        dfs(grid, vis, i - 1, j);
        dfs(grid, vis, i + 1, j);
        dfs(grid, vis, i, j - 1);
        dfs(grid, vis, i, j + 1);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size(), ans = 0, area = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 and !vis[i][j]) {
                    area = 0;
                    dfs(grid, vis, i, j);
                }
            }
        }
        return ans;
    }
};