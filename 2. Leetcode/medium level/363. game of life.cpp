// link to question - https://leetcode.com/problems/game-of-life/

class Solution {
public:
    bool check(int i, int j, vector<vector<int>>& a) {
        if(i < 0 or i == a.size() or j < 0 or j == a[0].size()) return 0;
        if(a[i][j] % 2) return 1;
        return 0;
    }
    
    void gameOfLife(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size(), cur, one;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cur = a[i][j] % 2;
                one = 0;
                
                if(check(i - 1, j - 1, a)) one++;
                if(check(i - 1, j, a)) one++;
                if(check(i - 1, j + 1, a)) one++;
                if(check(i, j - 1, a)) one++;
                if(check(i, j + 1, a)) one++;
                if(check(i + 1, j - 1, a)) one++;
                if(check(i + 1, j, a)) one++;
                if(check(i + 1, j + 1, a)) one++;
                
                if(cur == 0) {
                    if(one == 3) a[i][j] += 2;
                }
                else {
                    if(one == 2 or one == 3) a[i][j] += 2;
                }
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                a[i][j] /= 2;
            }
        }                
    }
};