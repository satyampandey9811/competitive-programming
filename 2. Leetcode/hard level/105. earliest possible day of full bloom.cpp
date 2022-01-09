// link to question - https://leetcode.com/problems/earliest-possible-day-of-full-bloom/

class Solution {
public:
    int earliestFullBloom(vector<int>& pt, vector<int>& gt) {
        int n = pt.size();
        vector<array<int, 2>> a(n);
        for (int i = 0; i < n; i++) {
            a[i][0] = gt[i];
            a[i][1] = pt[i];
        }
        
        sort(a.rbegin(), a.rend());
        int sum = 0, ans = 0;
        
        for (int i = 0; i < n; i++) {
            sum += a[i][1];
            ans = max(ans, sum + a[i][0]);
        }

        return ans;
    }
};