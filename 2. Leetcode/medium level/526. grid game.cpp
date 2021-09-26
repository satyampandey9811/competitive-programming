// link to question - https://leetcode.com/problems/grid-game/

class Solution {
public:
    long long gridGame(vector<vector<int>>& a) {
        int n = a[0].size();
        long long ans = LLONG_MAX;
        long long downt = 0LL;
        long long upright = 0LL;
        
        for(int i = 0; i < n; i++) {
            downt += a[1][i];
        }
        
        for(int i = n - 1; i >= 0; i--) {
            downt -= a[1][i];
            ans = min(ans, max(downt, upright));
            upright += a[0][i];
        }
        
        return ans;
    }
};