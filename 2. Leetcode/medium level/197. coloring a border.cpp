// link to question - https://leetcode.com/problems/coloring-a-border/

class Solution {
public:
    int m, n;
    vector<vector<int>> ans;
    vector<vector<bool>> vis;
    
    void dfs(vector<vector<int>>& grid, int i, int j, int& val, int& color) {
        if(i < 0 or j < 0 or i == m or j == n) return;
        if(vis[i][j] or grid[i][j] != val) return;
        vis[i][j] = true;
        if(i-1 < 0 or i+1 == m or j-1 < 0 or j+1 == n) ans[i][j] = color;
        else if(grid[i-1][j] != val) ans[i][j] = color;        
        else if(grid[i+1][j] != val) ans[i][j] = color;
        else if(grid[i][j-1] != val) ans[i][j] = color;
        else if(grid[i][j+1] != val) ans[i][j] = color;
        dfs(grid, i - 1, j, val, color);
        dfs(grid, i + 1, j, val, color);
        dfs(grid, i, j - 1, val, color);
        dfs(grid, i, j + 1, val, color);
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        if(grid[r0][c0] == color) return grid;
        m = grid.size(), n = grid[0].size();
        ans = grid;
        vis.resize(m, vector<bool>(n, false));
        dfs(grid, r0, c0, grid[r0][c0], color);
        return ans;
    }
};