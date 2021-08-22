// link to question - https://leetcode.com/problems/maximum-matrix-sum/

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& a) {
        int n = a.size(), c = 0, mn = INT_MAX;
        long long ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans += abs(a[i][j]);
                if(a[i][j] < 0) c++;
                mn = min(mn, abs(a[i][j]));
            }
        }
        
        if(c % 2 == 0) return ans;
        ans -= 2 * mn;
        return ans;
    }
};