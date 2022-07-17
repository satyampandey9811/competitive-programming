// link to question - https://leetcode.com/problems/query-kth-smallest-trimmed-number/

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& a, vector<vector<int>>& q) {
        int m = a.size(), n = q.size();
        vector<int> res(n);
        int len = a[0].size();
        int k, t;
        
        vector<vector<pair<string, int>>> b(len + 1);
        
        for (int i = 1; i <= len; i++) {
            for (int j = 0; j < m; j++) {
                b[i].push_back({a[j].substr(len - i), j});
            }
            sort(b[i].begin(), b[i].end());
        }
        
        for (int i = 0; i < n; i++) {
            k = q[i][0], t = q[i][1];
            res[i] = b[t][k - 1].second;
        }
        
        return res;
    }
};