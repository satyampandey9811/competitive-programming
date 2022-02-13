// link to question - https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating/

class Solution {
public:
    int minimumOperations(vector<int>& a) {
        int tc = 0, tb = 0, n = a.size();
        vector<int> b(100001), c(100001);
        
        for (int i = 0; i < n; i += 2) {
            b[a[i]]++;    
            tb++;
        }
        for (int i = 1; i < n; i += 2) {
            c[a[i]]++;
            tc++;
        }
        
        int bf = 0, bs = 0;
        int cf = 0, cs = 0;
        
        for (int i = 0; i < 100001; i++) {
            if (b[i] >= b[bf]) {
                bs = bf;
                bf = i;
            }
            else if (b[i] > b[bs]) bs = i;
        }
        
        for (int i = 0; i < 100001; i++) {
            if (c[i] >= c[cf]) {
                cs = cf;
                cf = i;
            }
            else if (c[i] > c[cs]) cs = i;
        }
        
        int ans = 1e8;
        if (bf != cf) {
            ans = tb - b[bf] + tc - c[cf];
        }
        else {
            ans = tb - b[bf] + tc - c[cs];
            ans = min(ans, tb - b[bs] + tc - c[cf]);
        }
        return ans;
    }
};