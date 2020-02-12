// link to question - https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& ind) {
        vector<vector<int>> a(n,vector<int>(m,0));
        
        for(int k=0;k<ind.size();k++){
            int i=ind[k][0];
            int j=ind[k][1];
            for(int b=0;b<m;b++) a[i][b]++;
            for(int b=0;b<n;b++) a[b][j]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]%2!=0) ans++;
            }
        }
        return ans;
    }
};