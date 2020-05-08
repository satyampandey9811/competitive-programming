// link to question - https://leetcode.com/problems/check-if-it-is-a-straight-line/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& a) {
        int n = a.size();        
        int x1, x2, x3, y1, y2, y3;
        for(int i = 2; i < n; i++) {
            x1 = a[i-2][0], y1 = a[i-2][1];
            x2 = a[i-1][0], y2 = a[i-1][1];
            x3 = a[i][0], y3 = a[i][1];
            if((y3- y2) * (x2 - x1) != (y2 - y1) * (x3 - x2))
                return 0;
        }
        return 1;
    }
};