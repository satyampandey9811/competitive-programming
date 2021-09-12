// link to question - https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& a) {
        int n = a.size();
        long long ans = 0;
        map<double, long long> m;
        
        for(int i = 0; i < n; i++) {
            double v = a[i][0] * 1.0 / a[i][1];
            m[v]++;
        }
        
        for(auto &i :m) {
            ans += (i.second * (i.second - 1)) / 2;
        }
        
        return ans;
    }
};