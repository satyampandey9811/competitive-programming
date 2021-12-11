// link to question - https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& a, int k) {
        int n = a.size();
        vector<array<int, 2>> b(n);
        for (int i = 0; i < n; i++) {
            b[i][0] = a[i];
            b[i][1] = i;
        }
        
        sort(b.begin(), b.end());
        vector<array<int, 2>> c(k);
        int ct = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            c[ct][0] = b[i][1];
            c[ct][1] = b[i][0];
            ct++;
            if (ct == k) break;
        }
        
        sort(c.begin(), c.end());
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            ans[i] = c[i][1];
        }
        
        return ans;
    }
};