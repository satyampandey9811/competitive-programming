// link to question - https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/

class Solution {
public:
    int maxConsecutive(int b, int t, vector<int>& s) {
        sort(s.begin(), s.end());
        int n = s.size();
        
        int ans = s[0] - b;
        for (int i = 1; i < n; i++) {
            ans = max(ans, s[i] - s[i - 1] - 1);
        }
        ans = max(ans, t - s.back());
        
        return ans;
    }
};