// link to question - https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& f, int sp, int k) {
        vector<int> a(2e5 + 10);
        int n = f.size(), m = a.size() - 5;
        
        for (int i = 0; i < n; i++) {
            a[f[i][0] + 1] = f[i][1];
        }
        
        for (int i = 1; i < m; i++) {
            a[i] += a[i-1];
        }
        
        int ans = 0;
        int sum = 0, step;
        
        for (int i = sp; i <= min(m, sp + k); i++) {
            sum = a[i+1] - a[sp];
            step = i - sp;
            step = k - step * 2;
            
            ans = max(ans, sum);
            if (step > 0) {
                ans = max(ans, sum + a[sp] - a[max(0, sp - step)]);
            }
        }
        
        for (int i = sp; i >= max(0, sp - k); i--) {
            sum = a[sp+1] - a[i];
            step = sp - i;
            step = k - step * 2;
            
            ans = max(ans, sum);
            if (step > 0) {
                ans = max(ans, sum + a[min(m, sp + step + 1)] - a[sp + 1]);
            }
        }
        
        return ans;
    }
};