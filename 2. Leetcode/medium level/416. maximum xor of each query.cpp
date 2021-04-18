// link to question - https://leetcode.com/problems/maximum-xor-for-each-query/

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& a, int mb) {
        int n = a.size(), x = 0, e = (1 << mb) - 1;
        for(int i = 0; i < n; i++) x ^= a[i];
        vector<int> ans(n);
        
        for(int i = 0; i < n; i++) {
            ans[i] = x ^ e;
            x ^= a[n-i-1];
        }
        
        return ans;
    }
};