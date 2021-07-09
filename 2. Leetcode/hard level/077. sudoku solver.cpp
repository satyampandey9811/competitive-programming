// link to question - https://leetcode.com/problems/sudoku-solver/

class Solution {
public:
    vector<vector<bool>> row, col, three;
    
    bool isValid(int i, int j, char c) {
        if(!row[i][c - '0']) {
            if(!col[j][c - '0']) {
                if(!three[(i/3)*3 + j/3][c - '0']) {
                    return 1;
                }
            }
        }
        return 0;
    }

    bool solve(vector<vector<char>>& a) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(a[i][j] != '.') continue;
                for(char c = '1'; c <= '9'; c++) {
                    if(isValid(i, j, c)) {
                        a[i][j] = c;
                        row[i][c - '0'] = 1;
                        col[j][c - '0'] = 1;
                        three[(i/3)*3 + j/3][c - '0'] = 1;

                        if(solve(a)) return 1;

                        a[i][j] = '.';
                        row[i][c - '0'] = 0;
                        col[j][c - '0'] = 0;
                        three[(i/3)*3 + j/3][c - '0'] = 0;
                    }
                }
                return 0;
            }
        }
        return 1;
    }
    
    void solveSudoku(vector<vector<char>>& a) {
        row.resize(10, vector<bool>(10, 0));
        col.resize(10, vector<bool>(10, 0));
        three.resize(10, vector<bool>(10, 0));
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(a[i][j] == '.') continue;
                row[i][a[i][j] - '0'] = 1;
                col[j][a[i][j] - '0'] = 1;
                three[(i/3)*3 + j/3][a[i][j] - '0'] = 1;
            }
        }
        
        solve(a);
    }
};