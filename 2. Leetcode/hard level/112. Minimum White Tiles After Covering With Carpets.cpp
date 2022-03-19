// link to question - https://leetcode.com/problems/minimum-white-tiles-after-covering-with-carpets/

class Solution {
public:
    int dp[1001][1001];
    int n, len;
    vector<int> count;
    
    int go (int i, int nc, string &a) {
        if (i >= n) return 0;
        if (nc == 0) return count[i];
        
        int &res = dp[i][nc];
        if (res != -1) return res;
        
        res = INT_MAX;
        
        if (a[i] == '0') {
            return res = go (i + 1, nc, a);
        }
        
        res = min(res, 1 + go (i + 1, nc, a));
        res = min(res, go (i + len, nc - 1, a));
        
        return res;
    }
    
    
    int minimumWhiteTiles(string f, int nc, int cl) {
        memset(dp, -1, sizeof dp);
        len = cl;
        n = f.size();
        
        count = vector<int>(n + 1);
        
        for (int i = n - 1; i >= 0; i--) {
            if (f[i] == '1') count[i]++;
            count[i] += count[i + 1];
        }
        
        return go (0, nc, f);
    }
};