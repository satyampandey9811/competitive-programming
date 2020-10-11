// link to question - https://leetcode.com/problems/maximal-network-rank/

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& a) {
        vector<vector<int>> edges(n, vector<int>(n));
        for(int i = 0; i < a.size(); i++) {
            int x = a[i][0], y = a[i][1];
            edges[x][y] = 1;
            edges[y][x] = 1;
        }
        
        int ans = 0;
        vector<int> v(n);        
        for(int i = 0; i < n; i++) {
            int c = 0;
            for(int j = 0; j < n; j++) {
                if(edges[i][j]) c++;
            }
            v[i] = c;
        }
        
        for(int i = 0; i < n; i++) {
            int c;
            for(int j = i + 1; j < n; j++) {
                c = v[i] + v[j];
                if(edges[i][j]) c--;
                ans = max(ans, c);
            }            
        }
        
        return ans;
    }
};