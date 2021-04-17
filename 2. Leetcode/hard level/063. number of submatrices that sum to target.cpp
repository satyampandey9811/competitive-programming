// link to question - https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& a, int t) {
        int ans = 0, m = a.size(), n = a[0].size(), sum;
        for(int i = 1; i < n; i++) a[0][i] += a[0][i-1];
        for(int i = 1; i < m; i++) a[i][0] += a[i-1][0];
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = i; k < m; k++) {
                    for(int l = j; l < n; l++) {
                        sum = a[k][l];
                        if(i - 1 >= 0) sum -= a[i-1][l];
                        if(j - 1 >= 0) sum -= a[k][j-1];
                        if(i - 1 >= 0 and j - 1 >= 0) sum += a[i-1][j-1];
                        if(sum == t) ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};