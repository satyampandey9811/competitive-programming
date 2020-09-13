// link to question - https://leetcode.com/problems/count-unhappy-friends/

class Solution {
public:                
    int unhappyFriends(int n, vector<vector<int>>& a, vector<vector<int>>& p) {
        int size = p.size(), ans = 0;        
        map<int, int> m;
        for(int i = 0; i < size; i++) {
            m[p[i][0]] = p[i][1];
            m[p[i][1]] = p[i][0];
        }
        
        vector<vector<int>> l(n, vector<int>(n));
        for(int i = 0; i < n; i++) {                        
            for(int j = 0; j < n - 1; j++) {
                l[i][a[i][j]] = j;
            }
        }
        
        int w, x, y, z;        
        for(int i = 0; i < n; i++) {
            w = i;
            x = m[i];
            
            for(int j = 0; j < n; j++) {
                if(j == w or j == x) continue;
                y = j;
                z = m[j];
                
                if(l[w][y] < l[w][x] and l[y][w] < l[y][z]) {
                    ans++;
                    break;
                }
            }
        }
        
        return ans;
    }
};