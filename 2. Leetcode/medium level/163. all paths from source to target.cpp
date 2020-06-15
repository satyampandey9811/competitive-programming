// link to question - https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:       
    vector<vector<int>> paths;
    
    void dfs(int s, int e, vector<int> path, vector<vector<int>>& graph) { 
        path.push_back(s);
        if(s == e) {
            paths.push_back(path);
            return;
        }        
        for(auto i: graph[s]) {
            dfs(i, e, path, graph);
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();        
        vector<int> path;        
        dfs(0, n - 1, path, graph);        
        return paths;
    }
};