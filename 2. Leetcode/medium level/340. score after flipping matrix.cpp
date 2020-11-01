// link to question - https://leetcode.com/problems/score-after-flipping-matrix/

class Solution {
public:
    int m, n;
    
    void col(int c, vector<vector<int>>& a) {
        for(int i = 0; i < m; i++) {
            a[i][c] = !a[i][c];
        }
    }
    
    int matrixScore(vector<vector<int>>& a) {
        m = a.size(), n = a[0].size();
        
        for(int i = 0; i < m; i++) {
            if(!a[i][0]) {
                for(int j = 0; j < n; j++) {
                    a[i][j] = !a[i][j];
                }
            }
        }
        
        for(int i = 1; i < n; i++) {
            int c = 0;
            for(int j = 0; j < m; j++) {
                if(a[j][i]) c++;
            }
            if(c < (m + 1) / 2) col(i, a);
        }
        
        int ans = 0;
        for(int i = 0; i < m; i++) {
            int num = 0;
            for(int j = n - 1; j >= 0; j--) {
                if(a[i][j]) num += pow(2, n - 1 - j);
            }
            ans += num;
        }
        
        return ans;
    }
};