// link to question - https://leetcode.com/problems/maximum-earnings-from-taxi/

class Solution {
public:
    long long dp[100001];
    
    long long go(int i, int &n, vector<vector<int>> &a, vector<vector<int>> &r) {
        if(i >= n) return 0LL;
        long long &ans = dp[i];
        if(ans != -1) return ans;
        
        ans = 0;
        for(auto &j :a[i]) {
            ans = max(ans, r[j][1] - i + r[j][2] + go(r[j][1], n, a, r));
        }
        ans = max(ans, go(i + 1, n, a, r));
        return ans;
    }
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& r) {
        vector<vector<int>> a(n + 1);
        for(int i = 0; i < (int)r.size(); i++) {
            a[r[i][0]].push_back(i);
        }
        memset(dp, -1LL, sizeof dp);
        return go(0, n, a, r);
    }
};