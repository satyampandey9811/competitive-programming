// link to question - https://leetcode.com/problems/possible-bipartition/

class Solution {
public:
    bool check(int i, vector<int>& color, vector<vector<int>>& a) {
        color[i] = 0;
        queue<int> q;
        q.push(i);

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            for (auto &i :a[node]) {
                if (color[i] == color[node]) return false;
                if (color[i] == -1) {
                    color[i] = 1 - color[node];
                    q.push(i);
                }
            }
        }
        
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> a(n);
        for (auto &i :dislikes) {
            a[i[0] - 1].push_back(i[1] - 1);
            a[i[1] - 1].push_back(i[0] - 1);
        }
        
        vector<int> color(n, -1);
        
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!check(i, color, a)) return false;
            }
        }
        
        return true;
    }
};