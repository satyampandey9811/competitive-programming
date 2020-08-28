// link to question - https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/

class Solution {
public:
    int dp[11][51][51];
    int m, n, mod = 1e9 + 7;
    vector<vector<int>> presum;
    
    int go(int r, int c, int k, vector<string>& pizza) {
        if(!presum[r][c]) return 0;
        if(!k) return 1;
        int &ans = dp[k][r][c];
        if(ans != -1) return ans;
        
        ans = 0;
        
        // horizontal cuts
        for(int i = r + 1; i < m; i++) {
            if(presum[r][c] - presum[i][c] > 0) {
                ans = (ans + go(i, c, k - 1, pizza)) % mod;
            }
        }
        
        // vertical cuts
        for(int i = c + 1; i < n; i++) {
            if(presum[r][c] - presum[r][i] > 0) {
                ans = (ans + go(r, i, k - 1, pizza)) % mod;
            }
        }
        
        return ans;
    }
    
    int ways(vector<string>& pizza, int k) {
        m = pizza.size(), n = pizza[0].size();
        presum.resize(m + 1, vector<int>(n + 1, 0));
        
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                presum[i][j] = presum[i+1][j] + presum[i][j+1] - 
                               presum[i+1][j+1] + (pizza[i][j] == 'A');
            }
        }
        
        memset(dp, -1, sizeof dp);
        return go(0, 0, k - 1, pizza);
    }
};