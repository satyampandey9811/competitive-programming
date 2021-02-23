// link to question - https://leetcode.com/problems/map-of-highest-peak/

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        queue<int> p, q;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(a[i][j]) {
                    p.push(i);
                    q.push(j);
                }
            }
        }
        
        while(p.size()) {
            for(int i = p.size(); i > 0; i--) {
                int r = p.front(), c = q.front();
                p.pop();
                q.pop();
                if(r - 1 >= 0 and !a[r-1][c] and !ans[r-1][c]) {
                    p.push(r-1);
                    q.push(c);
                    ans[r-1][c] = ans[r][c] + 1;
                }
                if(c - 1 >= 0 and !a[r][c-1] and !ans[r][c-1]) {
                    p.push(r);
                    q.push(c-1);
                    ans[r][c-1] = ans[r][c] + 1;
                }
                if(r + 1 < m and !a[r+1][c] and !ans[r+1][c]) {
                    p.push(r+1);
                    q.push(c);
                    ans[r+1][c] = ans[r][c] + 1;
                }
                if(c + 1 < n and !a[r][c+1] and !ans[r][c+1]) {
                    p.push(r);
                    q.push(c+1);
                    ans[r][c+1] = ans[r][c] + 1;
                }
            }
        }
        
        return ans;
    }
};