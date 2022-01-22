// link to question - https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range/

class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& a, vector<int>& p, vector<int>& s, int k) {
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int m = a.size(), n = a[0].size();
        
        queue<int> row, col;
        row.push(s[0]);
        col.push(s[1]);
        
        vector<vector<bool>> vis(m, vector<bool>(n));
        vis[s[0]][s[1]] = true;
        
        int r, c;
        int nr, nc, len;
        vector<vector<int>> ans;
        
        while (col.size()) {
            vector<array<int, 3>> store;
            
            for (int i = col.size(); i > 0; i--) {
                r = row.front();
                row.pop();
                c = col.front();
                col.pop();
                
                if (a[r][c] > 1 and a[r][c] >= p[0] and a[r][c] <= p[1]) {
                    store.push_back({a[r][c], r, c});
                }
                
                for (int j = 0; j < 4; j++) {
                    nr = dir[j][0] + r, nc = dir[j][1] + c;
                    
                    if (nr < 0 or nr >= m or nc < 0 or nc >= n or vis[nr][nc] or !a[nr][nc]) continue;
                    vis[nr][nc] = true;
                    
                    row.push(nr);
                    col.push(nc);
                }
            }
            
            sort (store.begin(), store.end());
            len = store.size();
            for (int i = 0; i < len; i++) {
                ans.push_back({store[i][1], store[i][2]});
                if (ans.size() == k) return ans;
            }
        }
        
        return ans;
    }
};