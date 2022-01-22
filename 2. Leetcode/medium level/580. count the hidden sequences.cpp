// link to question - https://leetcode.com/problems/count-the-hidden-sequences/

class Solution {
public:
    int numberOfArrays(vector<int>& d, int lower, int upper) {
        long long a = lower;
        int n = d.size();
        
        long long l = lower, h = lower;
        long long val, ans = 0;
        
        for (int i = 0; i < n; i++) {
            val = a + d[i];
            a = val;
            l = min(l, val);
            h = max(h, val);
        }
        
        if (l < lower) {
            h += lower - l;
            ans = max(0LL, upper - h + 1);
        }
        else if (l == lower) {
            ans = max(0LL, upper - h + 1);
        }
        
        return ans;
    }
};