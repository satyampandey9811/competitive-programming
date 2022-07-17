// link to question - https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/

class Solution {
public:
    int maximumSum(vector<int>& a) {
        int sum, y;
        int res = 0, len;
        vector<vector<int>> b(85);
        
        for (auto &i :a) {
            sum = 0;
            y = i;
            while (y > 0) {
                sum += y % 10;
                y /= 10;
            }
            b[sum].push_back(i);
        }
        
        for (int i = 0; i < 85; i++) {
            sort(b[i].begin(), b[i].end());
        }
        
        for (int i = 0; i < 85; i++) {
            len = b[i].size();
            if (len >= 2) {
                res = max(res, b[i][len - 1] + b[i][len - 2]);
            }
        }
        
        return res == 0 ? -1 : res;
    }
};