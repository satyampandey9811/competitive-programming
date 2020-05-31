// link to question - https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

class Solution {
public:
    void dfs(int start, int end, vector<vector<int>>& edges, vector<int>& visited, int& ans){        
        if(visited[start]) return;
        if(start != end) ans++;
        visited[start] = 1;
        
        for(auto x: edges[start])
            dfs(x, end, edges, visited, ans);
    }
         
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> edges(n);
        for(auto x: connections){
            edges[x[0]].push_back(x[1]);
        }
        int ans = 0;
        vector<int> visited(n);
        for(int i = 0; i < n; i++){            
            dfs(i, i, edges, visited, ans);
        }
        return ans;
    }
};