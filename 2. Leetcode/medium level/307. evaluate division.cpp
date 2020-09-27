// link to question - https://leetcode.com/problems/evaluate-division/

class Solution {
public:
    vector<vector<pair<int, float>>> edges;
    unordered_map<string, int> m;
    vector<double> ans;
    vector<bool> vis;
    
    bool dfs(int f, int s, float val) {
        if(f == s) {
            ans.push_back(val);
            return 1;
        }
        vis[f] = true;
        bool ans = 0;
        for(auto j: edges[f]) {            
            if(!vis[j.first]) {
                if(dfs(j.first, s, val * j.second)) { ans = 1; break; }
            }
        }
        vis[f] = false;
        return ans;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int c = 0;
        string f, s;
        float v;
        edges.resize(40);
        vis.resize(40);
        
        for(int i = 0; i < values.size(); i++) {
            f = equations[i][0], s = equations[i][1];
            v = values[i];
            if(m.count(f)) {
                if(m.count(s)) {
                    edges[m[f]].push_back({m[s], v});
                    edges[m[s]].push_back({m[f], 1.0/v});
                }
                else {
                    m[s] = c;
                    edges[m[f]].push_back({c, v});
                    edges[c].push_back({m[f], 1.0/v});
                    c++;
                }
            }
            else {
                if(m.count(s)) {
                    m[f] = c;
                    edges[c].push_back({m[s], v});
                    edges[m[s]].push_back({c, 1.0/v});
                    c++;                    
                }
                else {
                    m[f] = c;
                    c++;
                    m[s] = c;                    
                    edges[c-1].push_back({c, v});
                    edges[c].push_back({c-1, 1.0/v});
                    c++;
                }
            }
        }                
        
        for(int i = 0; i < queries.size(); i++) {
            f = queries[i][0], s = queries[i][1];       
            if(m.count(f) == 0 or m.count(s) == 0) ans.push_back(-1.0);
            else {
                if(!dfs(m[f], m[s], 1.0)) ans.push_back(-1.0);            
            }
        }        
        
        return ans;
    }
};