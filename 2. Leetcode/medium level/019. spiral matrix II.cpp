// link to question - https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> a(n, vector<int>(n));
        int l = 0, r = n - 1, t = 0, b = n - 1, val = 1;
        while(l <= r and t <= b){            
            for(int i = l; i <= r; i++)
                a[t][i] = val++;
            t++;                        
            for(int i = t; i <= b; i++)
                a[i][r] = val++;
            r--;                        
            for(int i = r; i >= l; i--)
                a[b][i] = val++;
            b--;                        
            for(int i = b; i >= t; i--)
                a[i][l] = val++;
            l++;            
        }
        return a;
    }
};