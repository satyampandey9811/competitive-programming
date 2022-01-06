// link to question - https://leetcode.com/problems/binary-trees-with-factors/

class Solution {
public:
    unordered_map<int, int> m;
    int dp[1001];
    int mod = 1e9 + 7, n;
    
    int go (int i, vector<int>& a) {
        int &ans = dp[i];
        if (ans != -1) return ans;
        
        ans = 0;
        for (int j = 0; j < i; j++) {
            if (a[i] % a[j] == 0 and m.count(a[i] / a[j])) {
                ans = (ans + go(j, a) % mod * 1LL * go(m[a[i] / a[j]], a) % mod) % mod;
            }
        }
        
        ans++;
        ans %= mod;
        return ans;
    }
    
    int numFactoredBinaryTrees(vector<int>& a) {
        memset(dp, -1, sizeof dp);
        n = a.size();
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) m[a[i]] = i;
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            ans = (ans + go(i, a)) % mod;
        }
        return ans;
    }
};