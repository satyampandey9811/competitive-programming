// link to question - https://leetcode.com/problems/find-all-groups-of-farmland/

class Solution {
public:
    int m, n;
    int r, c;
    
    void dfs(int i, int j, vector<vector<int>>& a, vector<vector<bool>>& vis) {
        if(i < 0 or j < 0 or i == m or j == n or a[i][j] == 0 or vis[i][j]) return;
        vis[i][j] = true;
        r = max(r, i);
        c = max(c, j);
        dfs(i - 1, j, a, vis);
        dfs(i + 1, j, a, vis);
        dfs(i, j - 1, a, vis);
        dfs(i, j + 1, a, vis);
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& a) {
        vector<vector<int>> ans;
        m = a.size(), n = a[0].size();
        r = -1, c = -1;
        vector<vector<bool>> vis(m, vector<bool>(n));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(a[i][j] == 1 and !vis[i][j]) {
                    dfs(i, j, a, vis);
                    ans.push_back({i, j, r, c});
                    r = -1, c = -1;
                }
            }
        }
        
        return ans;
    }
};