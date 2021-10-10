// link to question - https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/

class Solution {
public:
    int minOperations(vector<vector<int>>& a, int x) {
        int m = a.size(), n = a[0].size(), c = 0;
        vector<int> b(m * n);
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                b[c++] = a[i][j];
            }
        }
        
        sort(b.begin(), b.end());
        int size = b.size();
        
        int val = b[size / 2];
        int ans = 0;
        
        for(int i = 0; i < size; i++) {
            if(abs(val - b[i]) % x != 0) return -1;
            ans += abs(val - b[i]) / x;
        }
        
        return ans;
    }
};