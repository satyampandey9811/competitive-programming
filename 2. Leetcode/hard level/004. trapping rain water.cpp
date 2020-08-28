// link to question - https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size(), ans = 0;
        vector<int> ph(n), sh(n);
        if(n)
            ph[0] = a[0], sh[n - 1] = a[n - 1];
        for(int i = 1; i < n; i++)
            ph[i] = max(a[i], ph[i - 1]);
        for(int i = n - 2; i >= 0; i--)
            sh[i] = max(a[i], sh[i + 1]);                                
        for(int i = 0; i < n; i++)            
            ans += min(ph[i], sh[i]) - a[i];                
        return ans;
    }
};