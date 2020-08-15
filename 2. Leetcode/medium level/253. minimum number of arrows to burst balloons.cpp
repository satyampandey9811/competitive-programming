// link to question - https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& a) {
        int n = a.size();
        if(n == 0) return 0;
        sort(a.begin(), a.end());
        int s = a[0][0], e = a[0][1], ans = 0;
        
        for(int i = 1; i < n; i++) {
            if(e >= a[i][0]) {
                s = max(s, a[i][0]);
                e = min(e, a[i][1]);
            }
            else {
                ans++;
                s = a[i][0], e = a[i][1];
            }
        }
        
        return ans + 1;
    }
};