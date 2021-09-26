// link to question - https://leetcode.com/problems/check-if-word-can-be-placed-in-a-grid/

class Solution {
public:
    int m, n, k, s;
    
    void goh(int i, int j, vector<vector<char>>& a, vector<vector<int>>& h) {
        k = j;
        while(j < n) {
            if(a[i][j] == '#') break;
            h[i][k]++;
            j++;
        }
    }
    
    void gov(int i, int j, vector<vector<char>>& a, vector<vector<int>>& v) {
        k = i;
        while(i < m) {
            if(a[i][j] == '#') break;
            v[k][j]++;
            i++;
        }
    }
    
    bool placeWordInCrossword(vector<vector<char>>& a, string w) {
        m = a.size(), n = a[0].size(), s = w.size();
        vector<vector<int>> h(m, vector<int>(n)), v(m, vector<int>(n));
        
        for(int i = 0; i < m; i++) {
            if(a[i][0] != '#') goh(i, 0, a, h);
        }
        for(int i = 0; i < n; i++) {
            if(a[0][i] != '#') gov(0, i, a, v);
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(a[i][j] != '#' and a[i][j-1] == '#') goh(i, j, a, h);
            }
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(a[i][j] != '#' and a[i-1][j] == '#') gov(i, j, a, v);
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(h[i][j] == s) {
                    bool f = true;
                    for(int k = j, l = 0; l < s; k++, l++) {
                        if(a[i][k] != ' ' and a[i][k] != w[l]) {
                            f = false;
                            break;
                        }
                    }
                    if(f) return 1;
                    
                    f = true;
                    for(int k = j + s - 1, l = 0; l < s; k--, l++) {
                        if(a[i][k] != ' ' and a[i][k] != w[l]) {
                            f = false;
                            break;
                        }
                    }
                    if(f) return 1;
                }
                
                if(v[i][j] == s) {
                    bool f = true;
                    for(int k = i, l = 0; l < s; k++, l++) {
                        if(a[k][j] != ' ' and a[k][j] != w[l]) {
                            f = false;
                            break;
                        }
                    }
                    if(f) return 1;
                    
                    f = true;
                    for(int k = i + s - 1, l = 0; l < s; k--, l++) {
                        if(a[k][j] != ' ' and a[k][j] != w[l]) {
                            f = false;
                            break;
                        }
                    }
                    if(f) return 1;
                }
            }
        }
        
        return 0;
    }
};