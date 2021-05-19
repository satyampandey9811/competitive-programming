// link to question - https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

class Solution {
public:
    int minMoves2(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size(), avg = a[n/2], ans = 0;
        if(n % 2 == 0) {
            avg = (avg + a[n/2 -1]) / 2;
        }
        for(int i = 0; i < n; i++) ans += abs(a[i] - avg);
        return ans;
    }
};