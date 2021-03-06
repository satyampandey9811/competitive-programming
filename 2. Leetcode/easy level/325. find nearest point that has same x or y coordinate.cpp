// link to question - https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& a) {
        int ans = INT_MAX, n = a.size(), res;
        
        bool f = false;
        for(int i = 0; i < n; i++) {
            if(a[i][0] == x or a[i][1] == y) {
                f = true;
                int t = abs(a[i][0] - x) + abs(a[i][1] - y);
                if(ans > t) {
                    res = i;
                    ans = t;
                }
            }
        }
        
        if(!f) return -1;
        
        return res;
    }
};