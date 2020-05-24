// link to question - https://leetcode.com/problems/minimum-cost-for-tickets/

class Solution {
public:
    int f(vector<int>& days, vector<int>& costs, int s, int e, vector<int>& dp) {
        if(s == e)
            return 0;
        if(dp[s] != -1) 
            return dp[s];
        int a = costs[0] + f(days, costs, s + 1, e, dp);
        
        int ind = e, i;
        for(i = s + 1; i < e; i++) {
            ind = i;
            if(days[i] - days[s] >= 7) break;            
        }
        if(i == e) ind = e;
        int b = costs[1] + f(days, costs, ind, e, dp);   
        
        for(i = s + 1; i < e; i++) {
            ind = i;
            if(days[i] - days[s] >= 30) break;
        }
        if(i == e) ind = e;
        int c = costs[2] + f(days, costs, ind, e, dp);
        
        return dp[s] = min({a, b, c});
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, -1);
        return f(days, costs, 0, n, dp);
    }
};