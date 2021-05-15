// link to question - https://leetcode.com/problems/rotating-the-box/

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& a) {
        int m = a.size(), n = a[0].size();
        vector<vector<int>> c(m, vector<int>(n));
        vector<vector<char>> ans(n, vector<char>(m, '.'));
        
        for(int i = 0; i < m; i++) {
            int o = n - 1, v = 0;
            for(int j = n - 1; j >= 0; j--) {
                if(a[i][j] == '*') {
                    c[i][o] = v;
                    v = 0;
                    o = j;
                }
                else if(a[i][j] == '#') v++;
            }
            c[i][o] = v;
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = n - 1; j >= 0; j--) {
                int col = j;
                if(a[i][j] == '*') ans[j][m - i - 1] = '*', col = j - 1;
                if(c[i][j] > 0) {
                    int v = c[i][j];
                    while(v > 0) {
                        ans[col][m - i - 1] = '#';
                        col--;
                        v--;
                    }
                }
            }
        }
        
        return ans;
    }
};