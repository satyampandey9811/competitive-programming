// link to question - https://leetcode.com/problems/triangle/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& a) {
        int n = a.size();
        vector<int> b(a.back().begin(), a.back().end());
        
        for(int i = n - 2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                b[j] = min(b[j], b[j+1]) + a[i][j];
            }
        }
        
        return b[0];
    }
};