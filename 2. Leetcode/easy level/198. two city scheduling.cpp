// link to question - https://leetcode.com/problems/two-city-scheduling/

class Solution {
public:
    int help(int i, int a, int b, int n, vector<vector<int>>& costs, vector<vector<vector<int>>>& dp) {
        if(i == n) return 0;
        if(dp[i][a][b] != -1) return dp[i][a][b];
        int x = INT_MAX, y = INT_MAX;
        if(a != n/2) 
            x = costs[i][0] + help(i + 1, a + 1, b, n, costs, dp);    
        if(b != n/2) 
            y = costs[i][1] + help(i + 1, a, b + 1, n, costs, dp);        
        return dp[i][a][b] = min(x, y);
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n/2 + 1, vector<int>(n/2 + 1, -1)));
        return help(0, 0, 0, n, costs, dp);
    }
};