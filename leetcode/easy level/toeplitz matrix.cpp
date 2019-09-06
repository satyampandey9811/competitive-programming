// link to question - https://leetcode.com/problems/toeplitz-matrix/

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& a) {
        int m=a.size(),n=a[0].size();        
        for(int k=n-2;k>=0;k--){
            int x=a[0][k];
            for(int i=1,j=k+1;(i<m and j<n);i++,j++){
                if(x!=a[i][j])
                    return "False";
            }
        }
        for(int k=m-2;k>=1;k--){
            int x=a[k][0];
            for(int i=k+1,j=1;(i<m and j<n);i++,j++){
                if(x!=a[i][j])
                    return "False";
            }
        }
        
        return "True";
    }
};