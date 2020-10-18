// link to question - https://leetcode.com/problems/best-team-with-no-conflicts/

class Solution {
public:        
    int bestTeamScore(vector<int>& sc, vector<int>& age) {
        int n = age.size();
        vector<array<int, 2>> a(n);
        for(int i = 0; i < n; i++) {
            a[i][0] = age[i];
            a[i][1] = sc[i];
        }
        sort(a.begin(), a.end());  
        
        vector<int> dp(n + 1);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            dp[i] = a[i][1];
            for(int j = i - 1; j >= 0; j--) {
                if(a[j][1] <= a[i][1]) 
                    dp[i] = max(dp[i], dp[j] + a[i][1]);
            }
            ans = max(ans, dp[i]);
        }                
        return ans;
    }
};