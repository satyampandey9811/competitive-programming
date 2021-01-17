// link to question - https://leetcode.com/problems/largest-submatrix-with-rearrangements/

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size(), ans = 0;
        
        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(a[i][j]) a[i][j] += a[i-1][j];
            }
        }
        
        for(int i = 0; i < m; i++) {
            sort(a[i].begin(), a[i].end());
            for(int j = 0; j < n; j++) {
                ans = max(ans, a[i][j] * (n - j));
            }
        }
        
        return ans;
    }
};