// link to question - https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    void dfs(int i, int j, int m, int n, vector<vector<char>> &a){
        if(i < 0 or j < 0 or i > m or j > n or a[i][j] == '0') return;
        a[i][j] = '0';
        dfs(i - 1, j, m, n, a);
        dfs(i + 1, j, m, n, a);
        dfs(i, j - 1, m, n, a);
        dfs(i, j + 1, m, n, a);
    }
    
    int numIslands(vector<vector<char>>& a) {        
        int m = a.size(), n = m ?a[0].size() :0;
        int ans = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] == '1'){
                    ans++;
                    dfs(i, j, m - 1, n - 1, a);
                }                
            }
        }
        
        return ans;
    }
};