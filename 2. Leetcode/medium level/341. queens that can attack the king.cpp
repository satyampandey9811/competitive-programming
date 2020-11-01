// link to question - https://leetcode.com/problems/queens-that-can-attack-the-king/

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> ans;
        vector<vector<bool>> a(8, vector<bool>(8));
        for(int i = 0; i < queens.size(); i++) {
            a[queens[i][0]][queens[i][1]] = true;
        }
        
        int x = king[0], y = king[1];
        for(int i = y - 1; i >= 0; i--) {
            if(a[x][i]) {
                ans.push_back({x, i});
                break;
            }
        }
        
        for(int i = y + 1; i < 8; i++) {
            if(a[x][i]) {
                ans.push_back({x, i});
                break;
            }
        }
        
        for(int i = x - 1; i >= 0; i--) {
            if(a[i][y]) {
                ans.push_back({i, y});
                break;
            }
        }
        
        for(int i = x + 1; i < 8; i++) {
            if(a[i][y]) {
                ans.push_back({i, y});
                break;
            }
        }
        
        for(int i = x - 1, j = y - 1; i >= 0 and j >= 0; i--, j--) {
            if(a[i][j]) {
                ans.push_back({i, j});
                break;
            }
        }
        
        for(int i = x - 1, j = y + 1; i >= 0 and j < 8; i--, j++) {
            if(a[i][j]) {
                ans.push_back({i, j});
                break;
            }
        }
        
        for(int i = x + 1, j = y - 1; i < 8 and j >= 0; i++, j--) {
            if(a[i][j]) {
                ans.push_back({i, j});
                break;
            }
        }
        
        for(int i = x + 1, j = y + 1; i < 8 and j < 8; i++, j++) {
            if(a[i][j]) {
                ans.push_back({i, j});
                break;
            }
        }
        
        return ans;
    }
};