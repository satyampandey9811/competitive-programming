// link to question - https://leetcode.com/problems/sum-of-subarray-ranges/

class Solution {
public:
    long long subArrayRanges(vector<int>& a) {
        int n = a.size();
        long long ans = 0;
        int mx, mn;
        
        for (int i = 0; i < n; i++) {
            mn = INT_MAX, mx = INT_MIN;
            for (int j = i; j < n; j++) {
                mx = max(mx, a[j]);
                mn = min(mn, a[j]);
                ans += mx - mn;
            }
        }
        
        return ans;
    }
};