// link to question - https://leetcode.com/problems/minimum-time-to-complete-trips/

class Solution {
public:
    long long minimumTime(vector<int>& a, int tt) {
        long long ans, low = 0, mid, high = 1e18;
        int n = a.size();
        while (low <= high) {
            mid = low + (high - low) / 2;
            long long res = 0;
            for (int i = 0; i < n; i++) {
                res += mid / a[i];
                if (res >= tt) {
                    ans = mid;
                    high = mid - 1;
                    break;
                }
            }
            if (res < tt) low = mid + 1;
        }
        return ans;
    }
};