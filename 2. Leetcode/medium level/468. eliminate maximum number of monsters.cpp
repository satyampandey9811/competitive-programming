// link to question - https://leetcode.com/problems/eliminate-maximum-number-of-monsters/

class Solution {
public:
    int eliminateMaximum(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int mx = 0;
        for(int i = 0; i < n; i++) mx = max(mx, a[i] / b[i]);
        
        vector<int> c(mx + 1);
        for(int i = 0; i < n; i++) c[(a[i] - 1) / b[i]]++;
        
        int ans = 0, s = 0;
        for(int i = 0; i <= mx; i++) {
            ans++;
            int x = c[i] - s - 1;
            if(x > 0) break;
            s -= c[i] - 1;
        }
        
        return min(n, ans);
    }
};