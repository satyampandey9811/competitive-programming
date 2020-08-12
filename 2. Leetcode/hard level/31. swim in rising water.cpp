// link to question - https://leetcode.com/problems/swim-in-rising-water/

class Solution {
public:
    bool dfs(vector<vector<int>> &a, int i, int j, int &n, int &val) {
        if(i < 0 or j < 0 or i == n or j == n or a[i][j] > val) return 0;
        if(i == n - 1 and j == n - 1) return 1;
        
        a[i][j] = val + 1;                
        return dfs(a, i - 1, j, n, val) or dfs(a, i + 1, j, n, val) or
               dfs(a, i, j - 1, n, val) or dfs(a, i, j + 1, n, val);  
    }
    
    int swimInWater(vector<vector<int>>& mat) {
        int n = mat.size();
        int low = 0, high = n * n - 1, mid;
        
        while(low < high) {
            mid = low + (high - low) / 2;
            vector<vector<int>> a(n, vector<int>(n));
            
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    a[i][j] = (mat[i][j] <= mid) ? mid : mat[i][j];
                }
            }
            
            if(dfs(a, 0, 0, n, mid)) high = mid;
            else low = mid + 1;
        }
        
        return low;
    }
};