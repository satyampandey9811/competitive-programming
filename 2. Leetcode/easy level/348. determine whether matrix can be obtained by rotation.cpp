// link to question - https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/

class Solution {
public:
    int m, n;
    
    bool check(vector<vector<int>>&a, vector<vector<int>>& t) {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(a[i][j] != t[i][j]) return 0;
            }
        }
        return 1;
    }
    bool findRotation(vector<vector<int>>& a, vector<vector<int>>& t) {
        m = a.size(), n = a[0].size();
        
        if(check(a, t)) return 1;
        
        vector<vector<int>> b(n, vector<int>(n));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                b[j][n-i-1] = a[i][j]; 
            }
        }
        
        if(check(b, t)) return 1;
        
        vector<vector<int>> c(n, vector<int>(n));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                c[j][n-i-1] = b[i][j]; 
            }
        }
        
        if(check(c, t)) return 1;
        
        vector<vector<int>> d(n, vector<int>(n));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                d[j][n-i-1] = c[i][j]; 
            }
        }
        
        if(check(d, t)) return 1;
        
        return 0;
    }
};