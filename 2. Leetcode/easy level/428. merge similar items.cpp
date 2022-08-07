// link to question - https://leetcode.com/problems/merge-similar-items/

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<vector<int>> ans;
        vector<int> c(1001);
        for (auto &i :a) c[i[0]] += i[1];
        for (auto &i :b) c[i[0]] += i[1];
        for (int i = 1; i < 1001; i++) {
            if (c[i]) {
                ans.push_back({i, c[i]});
            }
        }
        return ans;
    }
};