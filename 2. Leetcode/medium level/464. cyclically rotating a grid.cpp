// link to question - https://leetcode.com/problems/cyclically-rotating-a-grid/

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& a, int k) {
        int m = a.size(), n = a[0].size();
        int z = k % (m * 2 + (n - 2) * 2);
        
        if(z == 0) return a;

        for(int x = 0; x < min(n / 2, m / 2); x++) {
            auto b = a;
            int z = k % ((m - 2 * x) * 2 + (n - 2 * x - 2) * 2);
            for(int y = 0; y < z; y++) {
                for(int i = x; i < m - 1 - x; i++) {
                    b[i+1][x] = a[i][x];
                }
                for(int i = x; i < n - 1 - x; i++) {
                    b[m-1-x][i+1] = a[m-1-x][i];
                }
                for(int i = m - 1 - x; i > x; i--) {
                    b[i-1][n-1-x] = a[i][n-1-x];
                }
                for(int i = n - 1 - x; i > x; i--) {
                    b[x][i-1] = a[x][i];
                }
                a = b;
            }
        }
        
        return a;
    }
};