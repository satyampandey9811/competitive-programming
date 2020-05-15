// link to question - https://leetcode.com/problems/maximum-sum-circular-subarray/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& a) {        
        int maxsum = -1e9, cmax = 0;
        int minsum = 1e9, cmin = 0;
        int n = a.size(), total = 0;
        
        for (int i = 0; i < n; i++) {
            total += a[i];
            cmin = min(a[i], cmin + a[i]);
            cmax = max(a[i], cmax + a[i]);
            minsum = min(cmin, minsum);
            maxsum = max(cmax, maxsum);
        }        
        if(maxsum < 1) 
            return maxsum;
        return max(maxsum, total - minsum);
    }
};