// link to question - https://leetcode.com/problems/ways-to-make-a-fair-array/

class Solution {
public:
    int waysToMakeFair(vector<int>& a) {
        int n = a.size(), ans = 0, odd = 0, even = 0;
        
        for(int i = 1; i < n; i += 2) even += a[i];
        for(int i = 2; i < n; i += 2) odd += a[i];
        
        if(even == odd) ans++;
        
        for(int i = 0; i < n - 1; i++) {
            if(i % 2 == 0) {
                even -= a[i+1];
                even += a[i];
            }
            else {
                odd -= a[i+1];
                odd += a[i];
            }
            if(even == odd) ans++;
        }
        
        return ans;
    }
};