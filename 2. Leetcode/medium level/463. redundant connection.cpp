// link to question - https://leetcode.com/problems/redundant-connection/

class Solution {
public:
    vector<vector<bool>> c;
    vector<vector<int>> edges;
    vector<bool> vis;
    int ans, n;
    
    bool go(int i, int p) {
        vis[i] = true;
        for(auto &j :edges[i]) {
            if(j == p) continue;
            if(vis[j]) {
                ans = j;
                c[i][j] = true;
                c[j][i] = true;
                return 1;
            }
            vis[j] = true;
            if(go(j, i)) {
                c[i][j] = true;
                c[j][i] = true;
                return i != ans;
            }
            vis[j] = false;
        }
        vis[i] = false;
        return 0;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& a) {
        n = a.size();
        c.resize(n + 1, vector<bool>(n + 1));
        edges.resize(n + 1);
        vis.resize(n + 1);
        
        for(int i = 0; i < n; i++) {
            edges[a[i][0]].push_back(a[i][1]);
            edges[a[i][1]].push_back(a[i][0]);
        }
        
        go(1, 0);
        
        for(int i = n - 1; i >= 0; i--) {
            if(c[a[i][0]][a[i][1]]) return {a[i][0], a[i][1]};
        }
        return {0, 0};
    }
};