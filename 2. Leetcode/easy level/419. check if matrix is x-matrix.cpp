// link to question - https://leetcode.com/problems/check-if-matrix-is-x-matrix/

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& a) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (a[i][i] == 0) return false;
            a[i][i] = -1;
        }
        int i = 0, j = n - 1;
        while (1) {
            if (a[i][j] == 0) return false;
            a[i][j] = -1;
            i++;
            j--;
            if (i == n) break;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == -1) continue;
                if (a[i][j]) return false;
            }
        }
        return true;
    }
};