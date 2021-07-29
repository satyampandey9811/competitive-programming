// link to question - https://leetcode.com/problems/01-matrix/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n));
        vector<vector<int>> ans(m, vector<int>(n));
        
        int dir[4][4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        queue<int> row, col, val;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!a[i][j]) {
                    row.push(i);
                    col.push(j);
                    val.push(1);
                }
            }
        }
        
        while(row.size()) {
            for(int i = row.size(); i > 0; i--) {
                int r = row.front(), c = col.front(), v = val.front();
                row.pop();
                col.pop();
                val.pop();
                
                for(int j = 0; j < 4; j++) {
                    int nr = r + dir[j][0], nc = c + dir[j][1];
                    if(nr < 0 or nr >= m or nc < 0 or nc >= n or !a[nr][nc] or vis[nr][nc]) continue;
                    
                    vis[nr][nc] = true;
                    ans[nr][nc] = v;
                    row.push(nr);
                    col.push(nc);
                    val.push(v + 1);
                }
            }
        }
        
        return ans;
    }
};