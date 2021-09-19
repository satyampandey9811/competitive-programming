// link to question - https://leetcode.com/problems/sum-of-beauty-in-the-array/

class Solution {
public:
    int sumOfBeauties(vector<int>& a) {
        int n = a.size();
        vector<int> b(n, 0), c(n, 1e7);
        b[0] = a[0];
        c[n-1] = a[n-1];
        
        for(int i = 1; i < n; i++) {
            b[i] = max(a[i], b[i-1]);
        }
        for(int i = n - 2; i > 0; i--) {
            c[i] = min(a[i], c[i+1]);
        }
        
        int ans = 0;
        for(int i = 1; i < n - 1; i++) {
            if(b[i-1] < a[i] and a[i] < c[i+1]) ans += 2;
            else if(a[i-1] < a[i] and a[i] < a[i+1]) ans++;
        }
        
        return ans;
    }
};