// link to question - https://leetcode.com/problems/minimum-distance-to-the-target-element/

class Solution {
public:
    int getMinDistance(vector<int>& a, int target, int start) {
        int n = a.size(), ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(a[i] == target) ans = min(ans, abs(i - start));
        }
        return ans;
    }
};