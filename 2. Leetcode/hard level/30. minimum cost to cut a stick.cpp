// link to question - https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

class Solution {
public:
    int dp[105][105];
    
    int dfs(int start, int end, int x, int y, vector <int>& cuts) {
        if(x > y) return 0;        
        int &ans = dp[x][y];
        if(ans != -1) return ans;
        
        ans = INT_MAX;
        for(int i = x; i <= y; i++) {            
            int a = dfs(start, cuts[i], x, i - 1, cuts);
            int b = dfs(cuts[i], end, i + 1, y, cuts);
            ans = min(ans, a + b + end - start);
        }
        
        return ans;        
    }
    
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        memset(dp, -1, sizeof dp);
        return dfs(0, n, 0, (int)cuts.size() - 1, cuts);
    }
};