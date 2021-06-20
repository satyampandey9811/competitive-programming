// link to question - https://leetcode.com/problems/count-sub-islands/

class Solution {
public:
    vector<vector<bool>> vis;
    int m, n;
    
    bool go(int i, int j, vector<vector<int>>& a, vector<vector<int>>& b) {
        if(i < 0 or i == m or j < 0 or j == n or !b[i][j] or vis[i][j]) return 1;
        if(!a[i][j]) return 0;
        vis[i][j] = true;
        bool w = 1;
        w &= go(i - 1, j, a, b);
        w &= go(i + 1, j, a, b);
        w &= go(i, j - 1, a, b);
        w &= go(i, j + 1, a, b);
        return w;
    }
    
    int countSubIslands(vector<vector<int>>& a, vector<vector<int>>& b) {
        m = a.size(), n = a[0].size();
        int ans = 0;
        vis.resize(m, vector<bool>(n));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(b[i][j] and !vis[i][j]) {
                    if(go(i, j, a, b)) ans++;
                }
            }
        }
        
        return ans;
    }
};