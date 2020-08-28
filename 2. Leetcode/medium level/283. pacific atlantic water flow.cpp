// link to question - https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution {
public:
    vector<vector<bool>> pacific, atlantic;
    int m, n;
    
    void dfs(int i, int j, int val, vector<vector<int>> &a, vector<vector<bool>> &ocean) {
        if(i < 0 or j < 0 or i == m or j == n or a[i][j] < val) return;
        if(ocean[i][j]) return;
        ocean[i][j] = true;
        
        dfs(i - 1, j, a[i][j], a, ocean);
        dfs(i + 1, j, a[i][j], a, ocean);
        dfs(i, j - 1, a[i][j], a, ocean);
        dfs(i, j + 1, a[i][j], a, ocean);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& a) {
        vector<vector<int>> ans;
        m = a.size();
        if(m == 0) return ans;
        n = a[0].size();
        pacific.resize(m, vector<bool>(n, false));
        atlantic.resize(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++) {
            if(!pacific[i][0]) dfs(i, 0, -1, a, pacific);
        }
        for(int i = 0; i < n; i++) {
            if(!pacific[0][i]) dfs(0, i, -1, a, pacific);
        }
        
        for(int i = 0; i < m; i++) {
            if(!atlantic[i][n-1]) dfs(i, n-1, -1, a, atlantic);
        }
        for(int i = 0; i < n; i++) {
            if(!atlantic[m-1][i]) dfs(m-1, i, -1, a, atlantic);
        }
                
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacific[i][j] and atlantic[i][j]) ans.push_back({i, j});
            }
        }
        
        return ans;
    }
};