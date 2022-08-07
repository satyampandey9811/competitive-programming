// link to question - https://leetcode.com/problems/reachable-nodes-with-restrictions/

class Solution {
public:
    set<int> s;
    
    int go (int i, vector<vector<int>>& a, vector<bool>& vis) {
        int ans = 0;
        vis[i] = true;
        
        for (auto &j :a[i]) {
            if (s.count(j) < 1 and !vis[j]) {
                ans += go (j, a, vis);
            }
        }
        
        return ans + 1;
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& r) {
        vector<vector<int>> a(n);
        for (auto &i :edges) {
            a[i[0]].push_back(i[1]);
            a[i[1]].push_back(i[0]);
        }
        for (auto &i :r) s.insert(i);
        
        vector<bool> vis(n);
        
        int ans = go(0, a, vis);
        return ans;
    }
};