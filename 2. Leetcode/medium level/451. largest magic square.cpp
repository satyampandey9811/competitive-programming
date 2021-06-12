// link to question - https://leetcode.com/problems/largest-magic-square/

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();
        int res = 1;
        
        vector<vector<int>> row(m, vector<int>(n + 1));
        vector<vector<int>> col(m + 1, vector<int>(n));
        vector<vector<int>> d1(m + 1, vector<int>(n + 1));
        vector<vector<int>> d2(m + 1, vector<int>(n + 1));
        
        for(int i = 0; i < m; i++) {
            for(int j = 1; j <= n; j++) {
                row[i][j] = row[i][j-1] + a[i][j-1];
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 1; j <= m; j++) {
                col[j][i] = col[j-1][i] + a[j-1][i];
            }
        }
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                d1[i][j] = d1[i-1][j-1] + a[i-1][j-1];
            }
        }
        
        for(int i = 1; i <= m; i++) {
            for(int j = n - 1; j >= 0; j--) {
                d2[i][j] = d2[i-1][j+1] + a[i-1][j];
            }
        }
        
        for(int x = 2; x <= min(m, n); x++) {
            for(int i = 0; i <= m - x; i++) {
                bool z = false;
                
                for(int j = 0; j <= n - x; j++) {
                    int v = row[i][j+x] - row[i][j];
                    bool f = true;
                    for(int g = i; g < i + x; g++) {
                        int val = row[g][j+x] - row[g][j];
                        if(val != v) {
                            f = false;
                            break;
                        }
                    }
                    if(!f) continue;
                    for(int g = j; g < j + x; g++) {
                        int val = col[i+x][g] - col[i][g];
                        if(val != v) {
                            f = false;
                            break;
                        }
                    }
                    if(!f) continue;
                    if(d1[i+x][j+x] - d1[i][j] != v) continue;
                    if(d2[i+x][j] - d2[i][j+x] != v) continue;
                    res = x;
                    z = true;
                    break;
                }
                
                if(z) break;
            }
        }
        
        return res;
    }
};