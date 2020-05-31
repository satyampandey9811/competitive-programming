// link to question - https://leetcode.com/problems/course-schedule-iv/

class Solution {
public:
    void dfs(int s, int e, vector<vector<int>>& edges, vector<vector<bool>>& st, vector<int>& vis) {
        if(s != e) st[s][e] = true;
        if(vis[s]) return;
        vis[s] = true;
        for(auto i: edges[s]) {
            dfs(i, e, edges, st, vis);
        }
    }
    
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        vector<vector<int>> edges(n);
        for(auto i: prerequisites) {
            edges[i[0]].push_back(i[1]);
        }
        vector<vector<bool>> st(n, vector<bool>(n, false));
        
        for(int i = 0; i < n; i++) {
            vector<int> vis(n);
            dfs(i, i, edges, st, vis);
        }
        
        vector<bool> ans;
        int m = queries.size();
        for(int i = 0; i < m; i++) {
            int x = queries[i][0], y = queries[i][1];
            ans.push_back(st[y][x]);            
        }
        
        return ans;
    }
};