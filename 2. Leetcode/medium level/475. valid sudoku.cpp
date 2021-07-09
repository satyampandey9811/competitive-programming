// link to question - https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& a) {
        int n = 9;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(a[i][j] == '.') continue;
                
                for(int k = 0; k < n; k++) {
                    if(k == j) continue;
                    if(a[i][k] == a[i][j]) return 0;
                }
                
                for(int k = 0; k < n; k++) {
                    if(k == i) continue;
                    if(a[k][j] == a[i][j]) return 0;
                }
                
                int k = i / 3, l = j / 3;
                k *= 3, l *= 3;
                
                for(int x = 0; x < 3; x++) {
                    for(int y = 0; y < 3; y++) {
                        if(k+x == i and y+l == j) continue;
                        if(a[k+x][y+l] == a[i][j]) return 0;
                    }
                }
            }
        }
        
        return 1;
    }
};