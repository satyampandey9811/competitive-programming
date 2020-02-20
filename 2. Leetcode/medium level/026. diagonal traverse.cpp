// link to question - https://leetcode.com/problems/diagonal-traverse/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& a) {
        vector<int> ans;                
        if(a.size() == 0) return {};
        int m = a.size(), n = a[0].size();
        int row, col, x, y;
        if(n > 1) row = 0, col = 1;
        else row = 1, col = 0;
        x = row, y = col;
        ans.push_back(a[0][0]);
        while(x < m and y < n){
            x = row;
            while(y >= 0 and x < m){
                ans.push_back(a[x][y]);
                x++, y--;
            }
            if(x == m)
                x--, y++;
            y++;
            if(x == m-1 and y == n-1){
                ans.push_back(a[x][y]);
                break;
            }
            while(x >= 0 and y < n){
                ans.push_back(a[x][y]);
                x--, y++;
            }
            if(y == n) 
                y--, row = x + 2;        
        }
        return ans;
    }
};