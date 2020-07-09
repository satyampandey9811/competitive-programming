// link to question - https://leetcode.com/problems/smallest-range-i/

class Solution {
public:
    int smallestRangeI(vector<int>& a, int k) {        
        ios::sync_with_stdio(false), cin.tie(0);
        int low = a[0], high = a[0];
        for(int i: a) low = min(low, i), high = max(high, i);
        if(low + k >= high - k) return 0;
        return high - k - low - k;
    }
};