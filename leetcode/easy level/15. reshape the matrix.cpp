// link to question - https://leetcode.com/problems/reshape-the-matrix/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& a, int r, int c) {
        
        
        vector<vector<int>> b(r,vector<int>(c));
                              
        int m=a.size(),n=a[0].size();
        if(r*c!=m*n)
          return a;                              
        int x=0,y=0;                      
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(x<r and y<c){
                    b[x][y]=a[i][j];
                    y++;
                }
                if(y==c){
                    y=0;x++;
                }
            }
        }       
        return b;                              
    }
};