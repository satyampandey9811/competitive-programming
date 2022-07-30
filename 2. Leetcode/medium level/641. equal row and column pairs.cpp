// link to question - https://leetcode.com/problems/equal-row-and-column-pairs/

class Solution {
public:
    int equalPairs(vector<vector<int>>& a) {
        int n = a.size(), ans = 0;
        map<vector<int>, int> m;
        for (auto &i :a) m[i]++;
        
        for (int i = 0; i < n; i++) {
            vector<int> col;
            for (int j = 0; j < n; j++) {
                col.push_back(a[j][i]);
            }
            ans += m[col];
        }
        
        return ans;
    }
};