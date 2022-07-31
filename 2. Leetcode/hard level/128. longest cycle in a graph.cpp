// link to question - https://leetcode.com/problems/longest-cycle-in-a-graph/

class Solution {
public:
    int ans;
    
    void find (int i, int val, vector<int>& a, vector<int>& dis, vector<bool>& vis, vector<bool>& dfsvis) {
        dfsvis[i] = true;
        dis[i] = val;
        vis[i] = true;
        int neigh = a[i];
        
        if (neigh != -1) {
            if (dfsvis[neigh]) {
                ans = max(ans, val - dis[neigh] + 1);
                dfsvis[i] = false;
                return;
            }
            
            if (vis[neigh]) {
                dfsvis[i] = false;
                return;
            }
            
            find (neigh, val + 1, a, dis, vis, dfsvis);
        }
        
        dfsvis[i] = false;
    }
    
    int longestCycle(vector<int>& a) {
        ans = -1;
        int n = a.size();
        vector<int> dis(n);
        vector<bool> dfsvis(n);
        vector<bool> vis(n);
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                find (i, 1, a, dis, vis, dfsvis);
            }
        }
        
        return ans;
    }
};