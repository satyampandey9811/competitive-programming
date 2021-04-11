// link to question - https://leetcode.com/problems/minimum-sideway-jumps/

class Solution {
public:
    vector<vector<int>> dp;
    int n;
    
    int go(int i, int j, vector<int> &a) {
        if(i == n) return 0;
        
        int &ans = dp[i][j];
        if(ans != -1) return ans;
        ans = 1e6;
        
        if(a[i+1] == j) {
            for(int k = 1; k < 4; k++) {
                if(k == j or k == a[i]) continue;
                ans = min(ans, go(i, k, a) + 1);
            }
        }
        else ans = go(i + 1, j, a);
        return ans;
    }
    
    int minSideJumps(vector<int>& a) {
        n = a.size();
        n--;
        dp.resize(n, vector<int>(4, -1));
        
        return go(0, 2, a);
    }
};