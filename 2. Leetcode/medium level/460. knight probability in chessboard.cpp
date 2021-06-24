// link to question - 460. knight probability in chessboard.cpp

class Solution {
public:
    double dp[26][26][101];
    vector<vector<int>> a = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}};
    
    double go(int i, int j, int c, int &n, int &mv) {
        if(i < 0 or j < 0 or i >= n or j >= n) return 0;
        if(c == mv) return 1;
        
        double &ans = dp[i][j][c];
        if(ans) return ans;
        
        ans = 0;
        for(int k = 0; k < 8; k++) {
            ans += (double)go(i + a[k][0], j + a[k][1], c+1, n, mv) / 8;
        }
        return ans;
    }
    
    double knightProbability(int n, int k, int r, int c) {
        memset(dp, 0, sizeof dp);
        return go(r, c, 0, n, k);
    }
};