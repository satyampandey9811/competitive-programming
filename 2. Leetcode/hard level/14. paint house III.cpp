// link to question - https://leetcode.com/problems/paint-house-iii/

class Solution {
public:
    int dp[102][25][102], m, n, t;
    vector<int> houses;
    vector<vector<int>> cost;
    
    int f(int ind, int prev, int nc) {
        if(ind == m) {
            if(nc == t) return 0;
            return 1e7;
        }
        
        int &ans = dp[ind][prev][nc];        
        if(ans != -1) return ans;
        
        int res = 1e7;
        
        if(houses[ind] > 0){
            if(houses[ind] == prev) res = f(ind + 1, houses[ind], nc);    
            else res = f(ind + 1, houses[ind], nc + 1);
            return ans = res;
        }
         
        for(int i = 1; i <= n; i++) {
            if(prev == i)
                res = min(res, f(ind + 1, i, nc) + cost[ind][i-1]);
            else
                res = min(res, f(ind + 1, i, nc + 1) + cost[ind][i-1]);
        }
        return ans = res;
    }
    
    int minCost(vector<int>& houses1, vector<vector<int>>& cost1, int m1, int n1, int target) {
        memset(dp, -1, sizeof dp);
        m = m1, n = n1, t = target;
        houses = houses1, cost = cost1;
        int ans = f(0, 22, 0);
        return ans >= 1e7 ? -1 : ans;
    }
};