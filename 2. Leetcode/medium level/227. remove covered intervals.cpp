// link to question - https://leetcode.com/problems/remove-covered-intervals/

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), [](auto x, auto y) {if(x[0] == y[0]) return x[1] > y[1]; else return x[0] < y[0];});
        int n = a.size(), ans = 0;
        for(int i = 0; i < n;) {
            ans++;
            int j = i + 1;
            while(j < n) {
                if(a[i][1] >= a[j][1]) j++;
                else break;
            }
            i = j;
        }
        return ans;
    }
};