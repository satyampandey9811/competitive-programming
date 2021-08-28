// link to question - https://leetcode.com/problems/maximum-profit-in-job-scheduling/

class Solution {
public:
    // important question
    int dp[50001];
    vector<int> start;
    
    int go(int i, int &n, vector<array<int, 3>> &a) {
        if(i == n) return 0;
        int &ans = dp[i];
        if(ans != -1) return ans;
        
        auto it = lower_bound(start.begin(), start.end(), a[i][1]) - start.begin();
        ans = a[i][2] + go(it, n, a);
        ans = max(ans, go(i + 1, n, a));
        return ans;
    }
    
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        int n = s.size();
        vector<array<int, 3>> a(n);
        for(int i = 0; i < n; i++) {
            a[i][0] = s[i], a[i][1] = e[i], a[i][2] = p[i];
        }
        sort(a.begin(), a.end(), [](array<int, 3> &x, array<int, 3> &y) {
            return x[0] <= y[0]; 
        });
        start = vector<int>(n);
        for(int i = 0; i < n; i++) start[i] = a[i][0];
        memset(dp, -1, sizeof dp);
        return go(0, n, a);
    }
};