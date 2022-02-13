// link to question - https://leetcode.com/problems/removing-minimum-number-of-magic-beans/

class Solution {
public:
    long long minimumRemoval(vector<int>& a) {
        int n = a.size();
        if (n == 1) return 0;
        vector<long long> b(n + 1);
        sort(a.begin(), a.end());
        for (int i = 1; i <= n; i++) {
            b[i] = b[i - 1] + a[i - 1];
        }
        
        long long ans = 1e18;
        long long sum = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            sum += a[i];
            ans = min(ans, b[i] + sum - (n - i) * 1LL * a[i]);
        }
        
        return ans;
    }
};