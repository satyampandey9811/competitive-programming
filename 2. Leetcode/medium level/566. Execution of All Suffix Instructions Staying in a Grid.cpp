// link to question - https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/

class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& sp, string s) {
        vector<vector<int>> a(n, vector<int>(n));
        int m = s.size();
        vector<int> ans(m);
        int c, row, col, j;
        
        for (int i = 0; i < m; i++) {
            c = 0;
            row = sp[0], col = sp[1], j = i;
            
            while (1) {
                if (s[j] == 'U') {
                    row--;
                }
                else if (s[j] == 'D') {
                    row++;
                }
                else if (s[j] == 'L') {
                    col--;
                }
                else {
                    col++;
                }
                if (row >= 0 and row < n and col >= 0 and col < n and j < m) c++;
                else break;
                j++;
            }
            
            ans[i] = c;
        }
        
        return ans;
    }
};