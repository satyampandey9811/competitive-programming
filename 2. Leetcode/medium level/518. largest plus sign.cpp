// link to question - https://leetcode.com/problems/largest-plus-sign/

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> a(n, vector<int>(n, 1));
        for(auto &i :mines) a[i[0]][i[1]] = 0;
        
        vector<vector<int>> left(n, vector<int>(n));
        vector<vector<int>> right(n, vector<int>(n));
        vector<vector<int>> up(n, vector<int>(n));
        vector<vector<int>> down(n, vector<int>(n));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                left[i][j] = a[i][j];
                if(a[i][j] and j > 0) left[i][j] += left[i][j-1];
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = n - 1; j >= 0; j--) {
                right[i][j] = a[i][j];
                if(a[i][j] and j < n - 1) right[i][j] += right[i][j+1];
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                up[j][i] = a[j][i];
                if(a[j][i] and j > 0) up[j][i] += up[j-1][i];
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = n - 1; j >= 0; j--) {
                down[j][i] = a[j][i];
                if(a[j][i] and j < n - 1) down[j][i] += down[j+1][i];
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(a[i][j]) {
                    ans = max(ans, 
                        min({left[i][j], right[i][j], up[i][j], down[i][j]})
                    );
                }
            }
        }
        
        return ans;
    }
};