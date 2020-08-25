// link to question - https://leetcode.com/problems/number-of-operations-to-make-network-connected/

class Solution {
public:    
    vector<vector<int>> graph;
    vector<bool> vis;
    
    void dfs(int node) {
        vis[node] = true;
        for(auto i: graph[node]) {            
            if(vis[i]) continue;
            else dfs(i);
        }        
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {        
        if(connections.size() < n - 1) return -1;
        
        graph.resize(n);
        vis.resize(n, false);
        for(auto i: connections) {
            graph[i[0]].push_back(i[1]);            
            graph[i[1]].push_back(i[0]);            
        }
        
        int c = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                c++;
                dfs(i);                
            }
        }
    
        return c - 1;
    }
};