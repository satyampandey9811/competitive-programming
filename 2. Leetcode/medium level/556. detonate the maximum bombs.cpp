// link to question - https://leetcode.com/problems/detonate-the-maximum-bombs/

class Solution {
public:
    int go(int i, vector<bool>& vis, vector<vector<int>>& a) {
        vis[i] = true;
        int ans = 0;
        
        for (auto &j :a[i]) {
            if (!vis[j]) {
                ans += go(j, vis, a);
            }
        }
        
        return ans + 1;
    }
    
    int maximumDetonation(vector<vector<int>>& bomb) {
        int n = bomb.size();
        long long x, y, r;
        int ans = 0;
        
        vector<vector<int>> a(n);
        
        for (int i = 0; i < n; i++) {
            r = bomb[i][2];
            r *= r;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                x = bomb[i][0] - bomb[j][0];
                x *= x;
                y = bomb[i][1] - bomb[j][1];
                y *= y;
                if (x + y <= r) {
                    a[i].push_back(j);
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            vector<bool> vis(n);
            ans = max(ans, go(i, vis, a));
        }
        
        return ans;
    }
};