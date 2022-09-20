// link to question - https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/

class Solution {
public:
    int minGroups(vector<vector<int>>& a) {
        vector<int> b(1000002);
        int n = b.size();
        for (auto &i :a) {
            b[i[0]]++;
            b[i[1] + 1]--;
        }
        int ans = 0;
        for (int i = 1; i < n; i++) {
            b[i] += b[i - 1];
        }
        for (int i = 0; i < n; i++) {
            ans = max(ans, b[i]);
        }
        return ans;
    }
};