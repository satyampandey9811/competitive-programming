// link to question - https://leetcode.com/problems/assign-cookies/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size(), n = s.size(), ans = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for(int i = 0, j = 0; i < m and j < n; j++) {
            if(g[i] <= s[j]) i++, ans++;
        }
        return ans;
    }
};