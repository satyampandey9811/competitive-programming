// link to question - https://leetcode.com/problems/search-a-2d-matrix-ii/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t) {
        int m = a.size(),n;
        if(m)
            n = a[0].size();
        else 
            return false;
        int i = 0, j = n - 1;
        while(i < m and j >= 0){
            if(a[i][j] == t)
                return true;
            else if(a[i][j] < t)
                i++;
            else 
                j--;
        }
        return false;
    }
};