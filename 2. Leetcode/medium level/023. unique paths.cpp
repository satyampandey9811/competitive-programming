// link to question - https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {        
        vector<vector<int>> a(m, vector<int>(n, 1));
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                a[i][j] = a[i][j - 1] + a[i - 1][j];
            }
        }
        return a[m - 1][n - 1];
    }
};