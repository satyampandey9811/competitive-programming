// link to question - https://leetcode.com/problems/angle-between-hands-of-a-clock/

class Solution {
public:
    double angleClock(int h, int m) {
        double ans;
        double hd, hm;
        if(h == 12) h = 0;
        hd = (h * 30) + (double)((30 * m) / 60.0);
        hm = m * 6;
        ans = abs(hd - hm);
        if(ans == 360.0) ans = 0;
        if(ans > 180.0) ans = 360.0 - ans;
        return ans;
    }
};