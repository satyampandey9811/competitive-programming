// link to question - https://leetcode.com/problems/minimum-degree-of-a-connected-trio-in-a-graph/

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& e) {
        vector<vector<int>> a(n + 1, vector<int>(n + 1)), b(n + 1);
        vector<int> w(n + 1);
        
        for(auto& i: e) {
            a[i[0]][i[1]] = 1;
            a[i[1]][i[0]] = 1;
            b[i[0]].emplace_back(i[1]);
            b[i[1]].emplace_back(i[0]);
            w[i[0]]++;
            w[i[1]]++;
        }
        
        bool f = false;
        
        int ans = INT_MAX, d = 0;
        
        for(int i = 0; i < e.size(); i++) {
            int x = e[i][0], y = e[i][1];
            
            if(b[y].size() < b[x].size()) {
                for(int j = 0; j < b[y].size(); j++) {
                    if(a[b[y][j]][x]) {
                        f = true;
                        d = w[x] - 2 + w[y] - 2 + w[b[y][j]] - 2;
                        ans = min(ans, d);
                    }
                }
            }
            else {
                for(int j = 0; j < b[x].size(); j++) {
                    if(a[b[x][j]][y]) {
                        f = true;
                        d = w[x] - 2 + w[y] - 2 + w[b[x][j]] - 2;
                        ans = min(ans, d);
                    }
                }
            }
        }
        
        if(!f) return -1;
        
        return ans;

    }
};