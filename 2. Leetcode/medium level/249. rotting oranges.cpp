// link to question - https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int m, n, ans;
    vector<vector<int>> time;
    
    void dfs(int i, int j, vector<vector<int>>& a, int t) {
        if(i < 0 or j < 0 or i == m or j == n or a[i][j] != 1) return;        
        int temp = a[i][j];
        a[i][j] = 3;
        
        if(time[i][j] != -1) time[i][j] = min(time[i][j], t);
        else time[i][j] = t;
        
        dfs(i - 1, j, a, t + 1);
        dfs(i + 1, j, a, t + 1);
        dfs(i, j - 1, a, t + 1);
        dfs(i, j + 1, a, t + 1);        
        
        a[i][j] = temp;
    }
    
    int orangesRotting(vector<vector<int>>& a) {
        m = a.size(), n = a[0].size();
        time.resize(m, vector<int>(n, -1));
        ans = 0;                 
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(a[i][j] == 2) {
                    dfs(i - 1, j, a, 1);
                    dfs(i + 1, j, a, 1);
                    dfs(i, j - 1, a, 1);
                    dfs(i, j + 1, a, 1);
                }
            }
        }
                
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(a[i][j] == 1 and time[i][j] == -1) return -1;
                else ans = max(ans, time[i][j]);
            }
        }        
        
        return ans;
    }
};