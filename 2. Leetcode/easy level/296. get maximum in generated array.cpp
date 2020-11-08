// link to question - https://leetcode.com/problems/get-maximum-in-generated-array/

class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0) return 0;
        
        vector<int> a(n + 1);
        a[1] = 1;
        
        for(int i = 1; i < n; i++) {
            if(2 * i >= 2 and 2 * i <= n) a[2 * i] = a[i];
            if(2 * i + 1 >= 2 and 2 * i + 1 <= n) a[2 * i + 1] = a[i] + a[i + 1];
        }
        
        int ans = 0;
        for(int i = 0; i <= n; i++) {
            ans = max(ans, a[i]);            
        }
        return ans;
    }
};