// link to question - https://leetcode.com/problems/n-queens/

class Solution {
public:
    vector<vector<string>> ans;  
    int n;
    
    bool check(int i, int j, vector<string>& a) {
        int row = i - 1, col = j - 1;
        while(row >= 0) {
            if(a[row--][j] == 'Q') return 0;
        }
        row = i - 1;
        while(row >= 0 and col >= 0) {
            if(a[row--][col--] == 'Q') return 0;
        }
        row = i - 1, col = j + 1;
        while(row >= 0 and col < n) {
            if(a[row--][col++] == 'Q') return 0;
        }
        return 1;
    }
    
    void backtrack(int i, vector<string>& a) {
        if(i == n) {
            ans.push_back(a);
            return;
        }
        
        for(int j = 0; j < n; j++) {            
            if(check(i, j, a)) {
                a[i][j] = 'Q';
                backtrack(i + 1, a);                
            }
            a[i][j] = '.';
        }
    }
    
    vector<vector<string>> solveNQueens(int m) {
        n = m;
        string s(n, '.');
        vector<string> a(n);
        for(int i = 0; i < n; i++) a[i] = s;
        backtrack(0, a);
        return ans;
    }
};