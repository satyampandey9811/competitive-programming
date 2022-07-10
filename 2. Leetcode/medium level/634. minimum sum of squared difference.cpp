// link to question - https://leetcode.com/problems/minimum-sum-of-squared-difference/

class Solution {
public:
    long long minSumSquareDiff(vector<int>& a, vector<int>& b, int k1, int k2) {
        long long ans = 0;
        int n = a.size(), k = k1 + k2, x;
        vector<int> c(100001);
        
        for (int i = 0; i < n; i++) {
            c[abs(a[i] - b[i])]++;
        }
        
        for (int i = 100000; i > 0; i--) {
            if (c[i] == 0) continue;
            x = min(c[i], k);
            k -= x;
            c[i] -= x;
            c[i - 1] += x;
            if (k == 0) break;
        }
        
        for (int i = 1; i < 100001; i++) {
            ans += c[i] * 1LL * i * i;
        }
        
        return ans;
    }
};