// link to question - https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/

class Solution {
public:
    int minDifference(vector<int>& a) {
        int n = a.size();
        if(n < 4) return 0;
        sort(a.begin(), a.end());
        int ans = INT_MAX;
        ans = min({ans, a[n-4]-a[0], a[n-1]-a[3], a[n-3]-a[1], a[n-2]-a[2]});
        return ans;
    }
};