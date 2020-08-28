// link to question - https://leetcode.com/problems/detect-cycles-in-2d-grid/

class Solution {
public:
    vector<vector<bool>> vis;
    vector<vector<char>> a;
    int m, n;
    
    bool go(char c, int i, int j, int pi, int pj, int len) {
        if(i < 0 or j < 0 or i == m or j == n or a[i][j] != c) return 0;   
        if(vis[i][j] and len > 3) return 1;
        if(vis[i][j]) return 0;    
        vis[i][j] = true;
        
        bool ans = false;
        
        if(i != pi or j - 1 != pj) 
            ans |= go(c, i, j - 1, i, j, len + 1);
        if(!ans and (i != pi or j + 1 != pj))
            ans |= go(c, i, j + 1, i, j, len + 1);
        if(!ans and (i - 1 != pi or j != pj))
            ans |= go(c, i - 1, j, i, j, len + 1);
        if(!ans and (i + 1 != pi or j != pj))
            ans |= go(c, i + 1, j, i, j, len + 1);
                
        return ans;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        ios::sync_with_stdio(false), cin.tie(0);
        a = grid;
        m = a.size(), n = a[0].size();
        vis.resize(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j]) {
                    if(go(a[i][j], i, j, -1, -1, 0)) return 1;
                }
            }
        }
        
        return 0;
    }
};