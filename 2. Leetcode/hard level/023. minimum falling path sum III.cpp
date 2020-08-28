// link to question - https://leetcode.com/problems/minimum-falling-path-sum-ii/

class Solution {
public:    
    int minFallingPathSum(vector<vector<int>>& a) {
        int n = a.size();        
        for(int i = n - 2; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                int val = INT_MAX;
                for(int k = 0; k < n; k++) {
                    if(k == j) continue;
                    val = min(val, a[i+1][k]);
                }
                a[i][j] += val;
            }
        }
        return *min_element(a[0].begin(), a[0].end());
    }
};