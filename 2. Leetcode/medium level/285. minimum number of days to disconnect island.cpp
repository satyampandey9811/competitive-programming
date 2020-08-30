// link to question - https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/

class Solution {
public:
    int m, n;
    
    void dfs(int i, int j, vector<vector<int>> &a, vector<vector<bool>> &vis) {
        if(i < 0 or j < 0 or i == m or j == n or a[i][j] == 0) return;
        if(vis[i][j]) return;
        vis[i][j] = true;
        
        dfs(i - 1, j, a, vis);
        dfs(i + 1, j, a, vis);
        dfs(i, j - 1, a, vis);
        dfs(i, j + 1, a, vis);
    }
    
    int minDays(vector<vector<int>>& a) {
        m = a.size(), n = a[0].size();
        int i, j;
        // check for zero
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for(i = 0; i < m; i++) {
            bool f = true;
            for(j = 0; j < n; j++) {
                if(a[i][j]) {                    
                    dfs(i, j, a, vis);
                    f = false;
                    break;
                }
            }
            if(!f) break;
        }
        for(; i < m; i++) {
            for(j = 0; j < n; j++) {
                if(a[i][j] and !vis[i][j]) return 0;
            }
        }
        
        // check for 1
        for(i = 0; i < m; i++) {
            for(j = 0; j < n; j++) {                
                if(a[i][j]) {
                    a[i][j] = 0;    
                    
                    vector<vector<bool>> visi(m, vector<bool>(n, false));
                    if(j + 1 < n and a[i][j+1]) dfs(i, j+1, a, visi);
                    else if(i + 1 < m and a[i+1][j]) dfs(i+1, j, a, visi);
                    else if(i - 1 >= 0 and a[i-1][j]) dfs(i-1, j, a, visi);
                    else if(j - 1 >= 0 and a[i][j-1]) dfs(i, j-1, a, visi);
                    
                    for(int k = 0; k < m; k++) {
                        for(int l = 0; l < n; l++) {
                            if(a[k][l] and !visi[k][l]) return 1;
                        }
                    }
                    
                    a[i][j] = 1;
                }
            }
        }
        
        // else answer is 2
        return 2;
    }
};