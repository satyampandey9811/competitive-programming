// link to question - https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/

class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> b(n + 1);
        
        int zero = 0, one = 0;
        for (int i = 0; i < n; i++) {
            if (a[i]) one++;
        }
        
        for (int i = 0; i < n; i++) {
            b[zero + one].push_back(i);
            if (!a[i]) zero++;
            else one--;
        }
        b[zero].push_back(n);
        
        for (int i = n; i >= 0; i--) {
            if (b[i].size() > 0) {
                return b[i];
            }
        }
        return {};
    }
};