// link to question - https://leetcode.com/problems/count-number-of-rectangles-containing-each-point/

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& a, vector<vector<int>>& p) {
        vector<vector<int>> b(101);
        for (auto &i :a) {
            b[i[1]].push_back(i[0]);
        }
        vector<int> len(101);
        for (int i = 0; i < 101; i++) {
            len[i] = b[i].size();
            sort(b[i].begin(), b[i].end());
        }
        int n = p.size();
        vector<int> ans(n);
        int h, l;
        
        for (int i = 0; i < n; i++) {
            l = p[i][0];
            h = p[i][1];
            
            for (int j = h; j < 101; j++) {
                auto it = lower_bound(b[j].begin(), b[j].end(), l) - b[j].begin();
                ans[i] += len[j] - it;
            }
        }

        return ans;
    }
};