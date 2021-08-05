// link to question - https://leetcode.com/problems/stone-game/

class Solution {
public:
    int dp[501][501];
    
    int go(int i, int j, vector<int>& piles) {
        if(i == j) return piles[i];
        int &ans = dp[i][j];
        if(ans != -1) return ans;
        
        ans = 0;
        ans = max(ans, piles[i] + go(i + 1, j, piles));
        ans = max(ans, piles[j] + go(i, j - 1, piles));
        return ans;
    }
    
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(dp, -1, sizeof dp);
        return go(0, n - 1, piles) > 0;
    }
};