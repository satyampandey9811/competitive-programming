// link to question - https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/

class Solution {
public:
    long long maximumSubsequenceCount(string a, string p) {
        int n = a.size();
        vector<int> d(n + 1);
        vector<int> c(n + 1);
        
        for (int i = 0; i < n; i++) {
            if (a[i] == p[0]) {
                d[i + 1]++;
            }
            d[i + 1] += d[i];
        }
        
        long long res = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] == p[1]) {
                res += d[i];
            }
        }
        
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] == p[1]) {
                c[i]++;
            }
            c[i] += c[i + 1];
        }
        
        long long ans = 0;
        
        for (int i = 0; i < n; i++) {
            if (a[i] == p[0]) {
                ans += c[i + 1];
            }
        }
        
        res += d[n];
        ans += c[0];
        
        res = max(ans, res);
        return res;
    }
};