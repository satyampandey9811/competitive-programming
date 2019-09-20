// link to question - https://leetcode.com/problems/available-captures-for-rook/

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& a) {
        int row,col,ans=0;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(a[i][j]=='R'){
                    
                    row = i, col = j - 1;
                    while(col >=0 and a[row][col]=='.') col--;
                    if(col >=0 and a[row][col] == 'p') ans++;                   

                    row = i - 1, col = j;
                    while(row >=0 and a[row][col]=='.') row--;
                    if(row >=0 and a[row][col] == 'p') ans++;                    

                    row = i, col = j + 1;
                    while(col < 8 and a[row][col]=='.') col++;
                    if(col <8 and a[row][col] == 'p') ans++;                    

                    row = i + 1, col = j;
                    while(row < 8 and a[row][col]=='.') row++;
                    if(row < 8 and a[row][col] == 'p') ans++;
                    
                    return ans;
                }                    
            }
        }      
        
        
        return ans;
    }
};