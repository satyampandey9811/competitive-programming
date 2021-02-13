// link to question - https://leetcode.com/problems/shortest-path-in-binary-matrix/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& a) {
        if(a[0][0]) return -1;
        int m = a.size(), n = a[0].size(), len = 1;
        
        vector<vector<bool>> vis(m, vector<bool>(n));
        queue<int> p, q;
        p.push(0);
        q.push(0);        
        vis[0][0] = true;
        
        while(p.size()) {
            for(int i = p.size(); i > 0; i--) {
                int f = p.front(), s = q.front();
                p.pop();
                q.pop();
                if(f == m - 1 and s == n - 1 and !a[f][s]) return len;
                
                for(int j = -1; j < 2; j++) {
                    for(int k = -1; k < 2; k++) {
                        if(f + j < 0 or f + j >= m or s + k < 0 or s + k >= n)
                            continue;
                        if(vis[f + j][s + k] or a[f + j][s + k]) continue;
                        vis[f + j][s + k] = true;
                        p.push(f + j);
                        q.push(s + k);
                    }
                }
            }
            len++;
        }
        
        return -1;
    }
};