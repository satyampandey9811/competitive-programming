// link to question - https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/

class Solution {
public:
    // important question
    int n;
    
    vector<vector<int>> dp;    // CORRECT ANSWER with 16 ms RUNTIME
    
    int go(int i, int mask, vector<int>& a, vector<int>& b) {
        if(i == n) return 0;
        int &ans = dp[i][mask];
        if(ans != -1) return ans;
        
        ans = INT_MAX;
        for(int j = 0; j < n; j++) {
            if(mask & (1 << j)) continue;
            mask ^= 1 << j;
            ans = min(ans, (b[j] ^ a[i]) + go(i + 1, mask, a, b));
            mask ^= 1 << j;
        }

        return ans;
    }
    
    int minimumXORSum(vector<int>& a, vector<int>& b) {
        n = a.size();
        dp.resize(n, vector<int>(1 << n, -1));
        return go(0, 0, a, b);
    }
};