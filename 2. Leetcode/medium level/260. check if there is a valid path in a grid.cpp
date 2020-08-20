// link to question - https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/

class Solution {
public:
    int m, n, val;
    vector<vector<int>> a;
    
    bool dfs(int i, int j) {
        
        if (i < 0 or j < 0 or i == m or j == n or !a[i][j]) return 0;
        
        val = a[i][j];
        a[i][j] = 0;
        bool ans = false;
        
        if (i == m - 1 and j == n - 1) return 1;
                 
        if (val == 1) {
            if (j + 1 < n and (a[i][j+1] == 1 or a[i][j+1] == 3 or a[i][j+1] == 5)) ans = dfs(i, j + 1);
            if (j - 1 >= 0 and (a[i][j-1] == 1 or a[i][j-1] == 4 or a[i][j-1] == 6)) ans |= dfs(i, j - 1);      
        }
        else if (val == 2) {
            if (i + 1 < m and (a[i+1][j] == 2 or a[i+1][j] == 5 or a[i+1][j] == 6)) ans = dfs(i + 1, j); 
            if (i - 1 >= 0 and (a[i-1][j] == 2 or a[i-1][j] == 3 or a[i-1][j] == 4)) ans |= dfs(i - 1, j);            
        }
        else if (val == 3) {
            if (j - 1 >= 0 and (a[i][j-1] == 1 or a[i][j-1] == 4 or a[i][j-1] == 6)) ans = dfs(i, j - 1);      
            if (i + 1 < m and (a[i+1][j] == 2 or a[i+1][j] == 5 or a[i+1][j] == 6)) ans |= dfs(i + 1, j);
        }
        else if (val == 4) {
            if (j + 1 < n and (a[i][j+1] == 1 or a[i][j+1] == 3 or a[i][j+1] == 5)) ans = dfs(i, j + 1);
            if (i + 1 < m and (a[i+1][j] == 2 or a[i+1][j] == 5 or a[i+1][j] == 6)) ans |= dfs(i + 1, j);
        }
        else if (val == 5) {
            if (j - 1 >= 0 and (a[i][j-1] == 1 or a[i][j-1] == 4 or a[i][j-1] == 6)) ans = dfs(i, j - 1);
            if (i - 1 >= 0 and (a[i-1][j] == 2 or a[i-1][j] == 3 or a[i-1][j] == 4)) ans |= dfs(i - 1, j);
        }
        else if (val == 6) {
            if (j + 1 < n and (a[i][j+1] == 1 or a[i][j+1] == 3 or a[i][j+1] == 5)) ans = dfs(i, j + 1);
            if (i - 1 >= 0 and (a[i-1][j] == 2 or a[i-1][j] == 3 or a[i-1][j] == 4)) ans |= dfs(i - 1, j);
        }
                
        return ans;
    }
    
    bool hasValidPath(vector<vector<int>>& grid) {        
        m = grid.size(), n = grid[0].size();        
        if (m == 1 and n == 1) return 1;
        a = grid;       
        return dfs(0, 0);
    }
};