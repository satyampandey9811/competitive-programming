// link to question - https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/

class Solution {
public:
    int nearestExit(vector<vector<char>>& a, vector<int>& e) {
        int m = a.size(), n = a[0].size();
        
        queue<int> p, q;
        p.push(e[0]);
        q.push(e[1]);

        int res = 0;
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vis[e[0]][e[1]] = 1;
        
        while(p.size()) {
            for(int i = p.size(); i > 0; i--) {
                
                int r = p.front();
                int c = q.front();
                p.pop();
                q.pop();
                
                if(r == 0 or r == m - 1 or c == 0 or c == n - 1) {
                    if((r != e[0] or c != e[1]) and a[r][c] == '.') return res;
                }
                
                if(r > 0 and !vis[r-1][c] and a[r-1][c] == '.') {
                    vis[r-1][c] = 1;
                    p.push(r-1);
                    q.push(c);
                }
                
                if(r < m - 1 and !vis[r+1][c] and a[r+1][c] == '.') {
                    vis[r+1][c] = 1;
                    p.push(r+1);
                    q.push(c);
                }
                
                if(c > 0 and !vis[r][c-1] and a[r][c-1] == '.') {
                    vis[r][c-1] = 1;
                    p.push(r);
                    q.push(c-1);
                }
                
                if(c < n - 1 and !vis[r][c+1] and a[r][c+1] == '.') {
                    vis[r][c+1] = 1;
                    p.push(r);
                    q.push(c+1);
                }   
            }
            
            res++;
        }
        
        return -1;
    }
};