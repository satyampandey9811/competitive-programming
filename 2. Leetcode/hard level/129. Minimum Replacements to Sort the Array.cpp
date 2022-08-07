// link to question - https://leetcode.com/problems/minimum-replacements-to-sort-the-array/

class Solution {
public:
    long long minimumReplacement(vector<int>& a) {
        int n = a.size();
        int prev = a[n - 1], t;
        long long ans = 0;
        
        for (int i = n - 2; i >= 0; i--) {
            t = (a[i] - 1) / prev;
            ans += t;
            prev = min(a[i], a[i] / (t + 1));
        }
        
        return ans;
    }
};