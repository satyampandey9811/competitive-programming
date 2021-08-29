// link to question - https://leetcode.com/problems/minimum-number-of-work-days/

class Solution {
public:
    // important question
    int n;
    int dp[16][1 << 15];
    
    int go(int t, int oc, int &st, vector<int>& a) {
        int &ans = dp[t][oc];
        if(ans != -1) return ans;
        ans = INT_MAX;
        
        for(int j = 0; j < n; j++) {
            if(oc & (1 << j)) continue;
            if(a[j] + t <= st) {
                oc ^= 1 << j;
                ans = min(ans, go(t + a[j], oc, st, a));
                oc ^= 1 << j;
            }
            else ans = min(ans, 1 + go(0, oc, st, a));
        }
        
        return ans = (ans == INT_MAX) ? 1 : ans;
    }
    
    int minSessions(vector<int>& a, int st) {
        sort(a.begin(), a.end());
        n = a.size();
        memset(dp, -1, sizeof dp);
        return go(0, 0, st, a);
    }
};