// link to question - https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/

class Solution {
public:
    vector<vector<int>> graph;
    
    int dfs(int node, int parent, vector<bool>& hasApple) {
        int ans = 0;        
        for(auto i: graph[node]) {
            if(i == parent) continue;
            ans += dfs(i, node, hasApple);
        }
        if(parent == -1) return ans;
        if(ans) return ans + 2;
        return hasApple[node] ? 2 : 0;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        graph.resize(n);
        for(auto i: edges) {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        return dfs(0, -1, hasApple);
    }
};