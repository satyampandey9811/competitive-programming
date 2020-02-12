// link to question - https://leetcode.com/problems/shift-2d-grid/

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& a, int k) {
        
        int m=a.size(), n=a[0].size();
        if(k%(m*n)==0) return a;
        k=k%(m*n);
    
        for(int l=1;l<=k;l++){
            int c=0;
            int temp=a[m-1][n-1];
            for(int i=m-1;i>=0;i--){
                for(int j=n-1;j>=0;j--){
                    if(i==0 and j==0){
                        c=1;break;
                    }
                    if(j==0){
                        a[i][j]=a[i-1][n-1];
                    }
                    else{
                        a[i][j]=a[i][j-1];
                    }
                }
                if(c)break;                
            }
            a[0][0]=temp;
        }
        return a;
    }
};