// link to question - https://leetcode.com/problems/k-radius-subarray-averages/

class Solution {
public:
    vector<int> getAverages(vector<int>& a, int k) {
        if (k == 0) return a;
        int n = a.size();
        vector<int> ans(n, -1);
        
        if (n < k) return ans;
        
        long long sum = 0;
        for (int i = 0; i < n and i < 2 * k; i++) sum += a[i];
        
        for (int i = k; i + k < n; i++) {
            sum += a[i + k];
            ans[i] = sum / (2 * k + 1);
            sum -= a[i - k];
        }
        
        return ans;
    }
};