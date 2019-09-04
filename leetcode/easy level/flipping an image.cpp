// link to question - https://leetcode.com/problems/flipping-an-image/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m=A.size(),n=A[0].size(),i,j;
        for(i=0;i<m;i++){
            reverse(A[i].begin(),A[i].end()); 
            for(j=0;j<n;j++){
                A[i][j]=1-A[i][j];
            }
        }        
        return A;
    }
};