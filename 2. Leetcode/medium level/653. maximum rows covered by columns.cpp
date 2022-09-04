// link to question - https://leetcode.com/problems/maximum-rows-covered-by-columns/

class Solution {
public:
    int ans, m, n;
    
    void go (int i, int nc, vector<vector<int>>& a, vector<int>& b, int& col) {
        if (nc == col) {
            int s = 0;
            for (int j = 0; j < m; j++) {
                if (b[j] == 0) s++;
            }
            ans = max(ans, s);
            return;
        }
        if (i == n) return;
        
        for (int j = 0; j < m; j++) {
            if (a[j][i]) b[j]--;
        }
        go (i + 1, nc + 1, a, b, col);
        
        for (int j = 0; j < m; j++) {
            if (a[j][i]) b[j]++;
        }
        go (i + 1, nc, a, b, col);
    }
    
    int maximumRows(vector<vector<int>>& a, int col) {
        ans = 0;
        m = a.size(), n = a[0].size();
        
        vector<int> b(m);
        for (int i = 0; i < m; i++) {
            int s = 0;
            for (int j = 0; j < n; j++) {
                s += a[i][j];
            }
            b[i] = s;
        }
        
        go (0, 0, a, b, col);
        
        return ans;
    }
};