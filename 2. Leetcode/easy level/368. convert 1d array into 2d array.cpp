// link to question - https://leetcode.com/problems/convert-1d-array-into-2d-array/

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& a, int m, int n) {
        vector<vector<int>> ans(m, vector<int>(n));
        int size = a.size();
        if(size != m * n) return {};
        
        int i = 0, j = 0;
        for(int k = 0; k < size; k++) {
            ans[i][j] = a[k];
            j++;
            if(j == n) j = 0, i++;
        }
        
        return ans;
    }
};