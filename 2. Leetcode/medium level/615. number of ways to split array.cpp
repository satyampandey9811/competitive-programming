// link to question - https://leetcode.com/problems/number-of-ways-to-split-array/

class Solution {
public:
    int waysToSplitArray(vector<int>& a) {
        int n = a.size();
        long long rsum = accumulate(a.begin(), a.end(), 0LL);
        long long lsum = 0;
        int ans = 0;
        
        for (int i = 0; i < n - 1; i++) {
            lsum += a[i];
            rsum -= a[i];
            if (lsum >= rsum) ans++;
        }
        
        return ans;
    }
};