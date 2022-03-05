// link to question - https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/

class Solution {
public:
    void dfs (int i, int j, vector<vector<int>>& ans, vector<vector<int>>& edges, vector<bool>& vis) {
        for (auto &k :edges[j]) {
            if (vis[k]) continue;
            vis[k] = true;
            ans[i].push_back(k);
            dfs(i, k, ans, edges, vis);
        }
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& a) {
        int e = a.size();
        vector<vector<int>> edges(n), ans(n);
        for (int i = 0; i < e; i++) {
            edges[a[i][1]].push_back(a[i][0]);
        }
        
        for (int i = 0; i < n; i++) {
            vector<bool> vis(n);
            dfs(i, i, ans, edges, vis);
        }
        
        for (int i = 0; i < n; i++) {
            sort(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};