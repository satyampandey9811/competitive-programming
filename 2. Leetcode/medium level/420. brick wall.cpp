// link to question - https://leetcode.com/problems/brick-wall/

class Solution {
public:
    int leastBricks(vector<vector<int>>& a) {
        int n = a.size(), ans = 0;
        unordered_map<int, int> m;
        
        for(int i = 0; i < n; i++) {
            int x = 0;
            for(int j = 0; j < a[i].size() - 1; j++) {
                x += a[i][j];
                m[x]++;
            }
        }
        
        for(auto& i: m) {
            ans = max(ans, i.second);
        }
        
        return n - ans;
    }
};