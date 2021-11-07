// link to question - https://leetcode.com/problems/maximum-path-quality-of-a-graph/

class Solution {
public:
    int m, n, ans, mt;
    
    void go(int i, int sum, int w, vector<int>& vis, vector<int>& value, vector<vector<pair<int, int>>>& a) {
        if(sum > mt) return;
        int st = 0;
        if(vis[i] == 0) st = value[i];
        vis[i]++;
        
        if(i == 0) ans = max(ans, w + st);
        
        for(auto &j :a[i]) {
            go(j.first, sum + j.second, w + st, vis, value, a);
        }
        
        vis[i]--;
        
        return;
    }
    
    int maximalPathQuality(vector<int>& value, vector<vector<int>>& edges, int mxt) {
        n = edges.size(), m = value.size(), ans = 0, mt = mxt;
        vector<vector<pair<int, int>>> a(m);
        
        for(int i = 0; i < n; i++) {
            a[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            a[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        vector<int> vis(m);
        
        go(0, 0, 0, vis, value, a);
        return ans;
    }
};