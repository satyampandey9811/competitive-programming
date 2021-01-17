// link to question - https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& a) {
        int maxl = 0, n = a.size();
        for(int i = 0; i < n; i++) {
            maxl = max(maxl, min(a[i][0], a[i][1]));
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(min(a[i][0], a[i][1]) == maxl) ans++;
        }
        
        return ans;
    }
};