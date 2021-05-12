// link to question - https://leetcode.com/problems/range-sum-query-2d-immutable/

class NumMatrix {
public:
    vector<vector<int>> a;
    int m, n;
    
    NumMatrix(vector<vector<int>>& mat) {
        m = mat.size(), n = mat[0].size();
        for(int i = 1; i < n; i++) mat[0][i] += mat[0][i-1];
        for(int i = 1; i < m; i++) mat[i][0] += mat[i-1][0];
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                mat[i][j] = mat[i][j] + mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
            }
        }
        a = mat;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = a[row2][col2];
        if(row1 > 0) ans -= a[row1-1][col2];
        if(col1 > 0) ans -= a[row2][col1-1];
        if(row1 > 0 and col1 > 0) ans += a[row1-1][col1-1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */