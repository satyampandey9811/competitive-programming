// link to question - https://leetcode.com/problems/stone-game-3/

class Solution {
public:
    int n;
    int dp[50001];
    
    int go(int i, vector<int>& a, vector<int>& sum) {
        if(i == n) return 0;
        int &ans = dp[i];
        if(ans != -1) return ans;
        
        ans = INT_MIN;
        int curr = 0;
        for(int j = i; j < min(n, i + 3); j++) {
            curr += a[j];
            ans = max(ans, curr - go(j + 1, a, sum));
        }
        return ans;
    }
    
    string stoneGameIII(vector<int>& a) {
        n = a.size();
        vector<int> sum(n + 1);
        for(int i = n - 1; i >= 0; i--) {
            sum[i] = a[i] + sum[i+1];
        }
        memset(dp, -1, sizeof dp);
        
        int diff = go(0, a, sum);
        
        if(diff > 0) return "Alice";
        if(diff == 0) return "Tie";
        return "Bob";
    }
};