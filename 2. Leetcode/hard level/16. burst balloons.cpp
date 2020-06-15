// link to question - https://leetcode.com/problems/burst-balloons/

class Solution {
public:
    int dp[501][501];
    
    int find(vector<int>& a, int i, int j) {
        if(i >= j) return 0;        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MIN;
        for(int k = i; k < j; k++) {
            int tempans = find(a, i, k) + find(a, k + 1, j);
            tempans += a[i-1] * a[k] * a[j];
            ans = max(ans, tempans);
        }
        
        return dp[i][j] = ans;
    }
    
    int maxCoins(vector<int>& a) {
        a.insert(a.begin(), 1);
        a.push_back(1);
        memset(dp, -1, sizeof dp);        
        return find(a, 1, a.size() - 1);
    }
};