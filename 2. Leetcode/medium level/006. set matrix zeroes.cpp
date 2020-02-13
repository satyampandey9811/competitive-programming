// link to question - https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        
        vector<int> b,c;
        for(int i=0;i<a.size();i++){
            int j;
            for(j=0;j<a[0].size();j++){
                if(a[i][j]==0){
                    b.push_back(j);
                    c.push_back(i);                    
                }
            }            
        }
        for(int i=0;i<b.size();i++){
            for(int j=0;j<a.size();j++)
                a[j][b[i]]=0;
        }
        for(int i=0;i<c.size();i++){
            for(int j=0;j<a[0].size();j++)
                a[c[i]][j]=0;
        }
    }
};