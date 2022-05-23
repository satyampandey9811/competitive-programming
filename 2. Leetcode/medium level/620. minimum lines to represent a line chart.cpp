// link to question - https://leetcode.com/problems/minimum-lines-to-represent-a-line-chart/

class Solution {
public:
    int minimumLines(vector<vector<int>>& a) {
        int n = a.size();
        if (n == 1) return 0;
        if (n == 2) return 1;
        vector<int> x, y;
        
        sort(a.begin(), a.end());
        
        for (int i = 0; i < n - 1; i++) {
            y.push_back(a[i + 1][1] - a[i][1]);
            x.push_back(a[i + 1][0] - a[i][0]);
        }
        
        int ans = 0;
        int len = x.size();
        
        for (int i = 0; i < len - 1; i++) {
            if (y[i] * 1LL * x[i + 1] != y[i + 1] * 1LL * x[i]) ans++;
        }
        
        return ans + 1;
    }
};