// link to question - https://leetcode.com/problems/matrix-diagonal-sum/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& a) {
        int sum = 0, n = a.size(), j = 0;
        for(int i = 0; i < n; i++) {
            sum += a[i][j++];
        }
        j = n - 1;
        for(int i = 0; i < n; i++) {
            sum += a[i][j--];
        }
        if(n & 1) {
            sum -= a[n/2][n/2];
        }
        return sum;
    }
};