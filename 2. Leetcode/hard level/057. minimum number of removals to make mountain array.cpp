// link to question - https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/

class Solution {
public:            
    int minimumMountainRemovals(vector<int>& a) {
        int n = a.size();
        vector<int> lis(n + 5, 1), lds(n + 5, 1);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[j] < a[i]) {
                    lis[i] = max(lis[i], 1 + lis[j]);
                }
            }
        }
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if(a[i] > a[j]) {
                    lds[i] = max(lds[i], 1 + lds[j]);
                }
            }
        }
        
        int ans = 1;
        for (int i = 1; i< n-1; i++){
            ans =max(ans, lis[i]+lds[i]-1);
        }
        return n-ans;
    }
};