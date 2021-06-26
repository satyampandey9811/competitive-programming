// link to question - https://leetcode.com/problems/maximum-alternating-subsequence-sum/

class Solution {
public:
    // important question
    long long maxAlternatingSum(vector<int>& a) {
        long long n = a.size(), ans = 0;
        long long even = 0, odd = a[0];
        
        for(int i = 1; i < n; i++) {
            long long e = even;
            e = max(even, odd - a[i]);
            odd = max(odd, even + a[i]);
            even = e;
        }
        
        return max(even, odd);
    }
};