// link to question - https://leetcode.com/problems/add-minimum-number-of-rungs/

class Solution {
public:
    int addRungs(vector<int>& a, int d) {
        int n = a.size();
        int ans = (a[0] - 1) / d;
        for(int i = 0; i < n - 1; i++) {
            ans += (a[i+1] - a[i] - 1) / d;
        }
        return ans;
    }
};