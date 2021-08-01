// link to question - https://leetcode.com/problems/making-a-large-island/

class Solution {
public:
    bool vis[501][501];
    int code[501][501];
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    unordered_map<int, int> m;
    int n;
    
    int dfs(int i, int j, int c, vector<vector<int>>& a) {
        vis[i][j] = true;
        code[i][j] = c;
        int ans = 0;
        
        for(int k = 0; k < 4; k++) {
            int nr = i + dir[k][0], nc = j + dir[k][1];
            if(nr < 0 or nr == n or nc < 0 or nc == n or vis[nr][nc] or !a[nr][nc])
                continue;
            ans += dfs(i + dir[k][0], j + dir[k][1], c, a);
        }
        
        return ans + 1;
    }
    
    int largestIsland(vector<vector<int>>& a) {
        n = a.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                vis[i][j] = false;
                code[i][j] = -1;
            }
        }
        
        int c = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j] and a[i][j]) {
                    m[c] = dfs(i, j, c, a);
                    c++;
                }
            }
        }
        
        int ans = 0;
        for(auto &i :m) ans = max(ans, i.second);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!a[i][j]) {
                    set<int> s;
                    int res = 0;
                    
                    for(int k = 0; k < 4; k++) {
                        int nr = i + dir[k][0], nc = j + dir[k][1];
                        
                        if(nr < 0 or nr == n or nc < 0 or nc == n) continue;
                        if(s.count(code[nr][nc])) continue;
                        s.insert(code[nr][nc]);
                        res += m[code[nr][nc]];
                    }
                    
                    ans = max(ans, res + 1);
                }
            }
        }
        
        return ans;
    }
};