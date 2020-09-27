// link to question - https://leetcode.com/problems/throne-inheritance/

class ThroneInheritance {
public:
    vector<vector<int>> edges;
    int n, c;
    unordered_map<string, pair<int, int>> m;
    unordered_map<int, string> mp;
    
    ThroneInheritance(string kingName) {
        n = 100001, c = 0;
        edges.resize(n);        
        m[kingName] = {c, 1};
        mp[c] = kingName;
        c++;        
    }
    
    void birth(string parentName, string childName) {        
        int x = m[parentName].first;
        edges[x].push_back(c);
        m[childName] = {c, 1};
        mp[c] = childName;
        c++;
    }
    
    void death(string name) {
        m[name].second = 0;
    }
    
    void dfs(int i, vector<string>& ans) {
        if(m[mp[i]].second) ans.push_back(mp[i]);
        for(auto j: edges[i]) {
            dfs(j, ans);
        }
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(0, ans);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */