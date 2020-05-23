// link to question - https://leetcode.com/problems/matrix-block-sum/

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& a, int k) {
        int m = a.size(), n = a[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int p = max(0, i - k);
                int q = min(m - 1, i + k);
                int r = max(0, j - k);
                int s = min(n - 1, j + k);
                for(int k = p; k <= q; k++) {
                    for(int l = r; l <= s; l++) {
                        ans[i][j] += a[k][l];
                    }
                }
            }
        }
        
        return ans;
    }
};