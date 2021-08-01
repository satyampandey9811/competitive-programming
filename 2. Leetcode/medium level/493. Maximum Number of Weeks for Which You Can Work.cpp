// link to question - https://leetcode.com/problems/maximum-number-of-weeks-for-which-you-can-work/

class Solution {
public:
    long long numberOfWeeks(vector<int>& a) {
        int n = a.size();
        long long ans = 0;
        sort(a.begin(), a.end());
        
        for(int i = 0; i < n - 1; i++) {
            ans += a[i];
        }
        
        ans += min(ans + 1, 1LL * a.back());
        return ans;
    }
};