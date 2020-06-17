// link to question - https://leetcode.com/problems/surrounded-regions/

class Solution {
public:
    int r, c;
    
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, int i, int j) {
        if(i < 0 or i == r or j < 0 or j == c) return;
        if(board[i][j] == 'X' or vis[i][j]) return;        
        vis[i][j] = true;
        dfs(board, vis, i - 1, j);
        dfs(board, vis, i, j - 1);
        dfs(board, vis, i + 1, j);
        dfs(board, vis, i, j + 1);
    }
    
    void solve(vector<vector<char>>& board) {
        r = board.size(), c = r > 0 ? board[0].size() : 0;        
        vector<vector<bool>> vis(r, vector<bool>(c, false));        
        for(int i = 0; i < r; i++) {
            if(board[i][0] == 'O' and !vis[i][0])
                dfs(board, vis, i, 0);
        }
        for(int i = 0; i < r; i++) {
            if(board[i][c-1] == 'O' and !vis[i][c-1])
                dfs(board, vis, i, c - 1);
        }
        for(int i = 0; i < c; i++) {
            if(board[0][i] == 'O' and !vis[0][i])
                dfs(board, vis, 0, i);
        }
        for(int i = 0; i < c; i++) {
            if(board[r-1][i] == 'O' and !vis[r-1][i])
                dfs(board, vis, r - 1, i);
        }
        
        for(int i = 1; i < r - 1; i++) {
            for(int j = 1; j < c - 1; j++) {
                if(board[i][j] == 'O' and !vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};