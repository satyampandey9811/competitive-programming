// link to question - https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int n) {
     
        vector<vector<int>> a(n);
        for(int i=0;i<n;i++){
            a[i].resize(i+1,1);
        }
        
        for(int i=2;i<n;i++){
            for(int j=1;j<a[i].size()-1;j++){
                a[i][j]=a[i-1][j-1]+a[i-1][j];
            }
        }        
        
        return a;
        
    }
};