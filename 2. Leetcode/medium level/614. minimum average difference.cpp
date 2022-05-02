// link to question - https://leetcode.com/problems/minimum-average-difference/

class Solution {
public:
    int minimumAverageDifference(vector<int>& a) {
        int n = a.size();
        int diff = INT_MAX;
        int ans;
        long long lsum = 0, rsum = accumulate(a.begin(), a.end(), 0LL);
        
        for (int i = 0; i < n; i++) {
            rsum -= a[i];
            lsum += a[i];
            
            long long r = rsum;
            if (n - i - 1 > 0) r /= (n - i - 1);
            
            int ad = abs(lsum / (i + 1) - r);
            if (ad < diff) {
                diff = ad;
                ans = i;
            }
        }
        
        return ans;
    }
};