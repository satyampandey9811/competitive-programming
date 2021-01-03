// link to question - https://leetcode.com/problems/beautiful-arrangement/

class Solution {
public:
    int ans;
    
    void go(int i, int& n, vector<vector<int>>& a, vector<int>& vis) {
        if(i == n + 1) {
            ans++;
            return;
        }
        for(int j = 0; j < a[i].size(); j++) {
            if(vis[a[i][j]]) continue;
            vis[a[i][j]] = true;
            go(i + 1, n, a, vis);
            vis[a[i][j]] = false;
        }
    }
    
    int countArrangement(int n) {
        vector<vector<int>> a(n + 1);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(j % i == 0 or i % j == 0) {
                    a[i].push_back(j);
                }
            }
        }
        
        ans = 0;
        vector<int> vis(n + 1);
        
        go(1, n, a, vis);
        return ans;
    }
};