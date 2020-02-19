// link to question - https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 and j == 0) continue;
                if(i == 0) a[i][j] += a[i][j - 1];
                else if(j == 0) a[i][j] += a[i - 1][j];
                else a[i][j] += min(a[i][j - 1], a[i - 1][j]);
            }
        }
        return a[m - 1][n - 1];
    }
};