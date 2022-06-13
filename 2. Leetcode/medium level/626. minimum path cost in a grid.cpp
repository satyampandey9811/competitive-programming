// link to question - https://leetcode.com/problems/minimum-path-cost-in-a-grid/

class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        int ans = 1e9;
        
        for (int i = m - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int val = 1e9;
                for (int k = 0; k < n; k++) {
                    val = min(val, grid[i + 1][k] + moveCost[grid[i][j]][k]);
                }
                grid[i][j] += val;
            }
        }
        
        for (int i = 0; i < n; i++) {
            ans = min(ans, grid[0][i]);
        }
        
        return ans;
    }
};