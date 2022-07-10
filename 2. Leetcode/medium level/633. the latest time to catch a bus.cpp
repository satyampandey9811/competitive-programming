// link to question - https://leetcode.com/problems/the-latest-time-to-catch-a-bus/

class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& a, vector<int>& b, int c) {
        int m = a.size(), n = b.size();
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int ans = 0, ct, j = 0;
        
        for (int i = 0; i < m; i++) {
            ct = 0;
            while (j < n and ct < c and b[j] <= a[i]) {
                if (j == 0) ans = b[j] - 1;
                if (j > 0 and b[j] != b[j - 1] + 1) ans = b[j] - 1;
                ct++;
                j++;
            }
            if (j > 0 and ct < c and b[j - 1] != a[i]) ans = a[i];
            if (j == 0 and ct < c) ans = a[i];
        }
        
        return ans;
    }
};