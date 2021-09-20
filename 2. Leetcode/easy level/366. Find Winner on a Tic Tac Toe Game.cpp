// link to question - https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/

class Solution {
public:
    int a[3][3];
    
    bool hasWon() {
        for(int i = 0; i < 3; i++) {
            if(a[i][0] == a[i][1] and a[i][1] == a[i][2]) return 1;
        }
        for(int i = 0; i < 3; i++) {
            if(a[0][i] == a[1][i] and a[1][i] == a[2][i]) return 1;
        }
        if(a[0][0] == a[1][1] and a[1][1] == a[2][2]) return 1;
        if(a[2][0] == a[1][1] and a[1][1] == a[0][2]) return 1;
        return 0;
    }
    
    string tictactoe(vector<vector<int>>& m) {
        int n = m.size(), v = 0, r, c, d = 2;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) a[i][j] = d++;
        }
        
        for(int i = 0; i < n; i++) {
            r = m[i][0], c = m[i][1];
            a[r][c] = v;
            if(hasWon()) {
                if(!v) return "A";
                return "B";
            }
            v = !v;
        }
        
        if(n == 9) return "Draw";
        return "Pending";
    }
};