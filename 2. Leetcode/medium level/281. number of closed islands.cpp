// link to question - https://leetcode.com/problems/number-of-closed-islands/

class Solution {
public:
    vector<vector<bool>> vis;
    int m, n;
    
    void dfs(int i, int j, vector<vector<int>> &a) {
        if(i < 0 or j < 0 or i == m or j == n) return;
        if(a[i][j] or vis[i][j]) return;        
        vis[i][j] = true;
                
        dfs(i - 1, j, a);
        dfs(i + 1, j, a);
        dfs(i, j - 1, a);
        dfs(i, j + 1, a);
    }
    
    int closedIsland(vector<vector<int>>& a) {
        m = a.size(), n = a[0].size();
        vis.resize(m, vector<bool>(n, false));
        int ans = 0;
        
        for(int i = 0; i < m; i++) {
            dfs(i, 0, a);
        }
        for(int i = 0; i < m; i++) {
            dfs(i, n - 1, a);
        }
        for(int i = 0; i < n; i++) {
            dfs(0, i, a);
        }
        for(int i = 0; i < n; i++) {
            dfs(m - 1, i, a);
        }
        
        for(int i = 1; i < m - 1; i++) {
            for(int j = 1; j < n - 1; j++) {
                if(!vis[i][j] and a[i][j] == 0) {
                    ans++;
                    dfs(i, j, a);
                }
            }
        }
        
        return ans;
    }
};