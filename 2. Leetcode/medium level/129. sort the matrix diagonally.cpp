// link to question - https://leetcode.com/problems/sort-the-matrix-diagonally/

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size(), i, j, k;
        for(i = 0; i < n - 1; i++) {
            vector<int> temp;
            k = i;
            for(j = 0; j < m and k < n; j++) {
                temp.push_back(a[j][k++]);
            }
            sort(temp.begin(), temp.end());
            k = i;
            for(j = 0; j < m and k < n; j++) {
                a[j][k++] = temp[j];
            }
        }
        
        for(i = 1; i < m - 1; i++) {
            vector<int> temp;
            k = i;
            for(j = 0; j < n and k < m; j++) {
                temp.push_back(a[k++][j]);
            }
            sort(temp.begin(), temp.end());
            k = i;
            for(j = 0; j < n and k < m; j++) {
                a[k++][j] = temp[j];
            }
        }
        return a;
    }
};