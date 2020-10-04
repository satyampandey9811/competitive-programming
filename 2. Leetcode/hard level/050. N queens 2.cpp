// link to question - https://leetcode.com/problems/n-queens-ii/

class Solution {
public:
    int ans, n;
    vector<vector<bool>> a;
    
    bool check(int i, int j) {
        int row = i - 1, col = j - 1;
        while(row >= 0) {
            if(a[row--][j]) return 0;
        }
        row = i - 1;
        while(row >= 0 and col >= 0) {
            if(a[row--][col--]) return 0;
        }
        row = i - 1, col = j + 1;
        while(row >= 0 and col < n) {
            if(a[row--][col++]) return 0;
        }
        return 1;
    }
    
    void backtrack(int i) {
        if(i == n) ans++;
        else {
            for(int j = 0; j < n; j++) {
                if(check(i, j)) {
                    a[i][j] = true;
                    backtrack(i + 1);
                    a[i][j] = false;
                }
            }
        }            
    }
    
    int totalNQueens(int m) {
        ans = 0;
        n = m;
        a.resize(n, vector<bool>(n));
        backtrack(0);
        return ans;
    }
};