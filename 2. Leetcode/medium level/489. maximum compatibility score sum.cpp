// link to question - https://leetcode.com/problems/maximum-compatibility-score-sum/

class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& s, vector<vector<int>>& m) {
        int ans = 0, n = s.size(), mx = 0;
        
        int c = 1;
        for(int i = 1; i <= n; i++) c *= i;
        
        for(int i = 0; i < c; i++) {
            mx = 0;
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < s[j].size(); k++) {
                    if(s[j][k] == m[j][k]) mx++;
                }
            }
            
            ans = max(ans, mx);
            
            next_permutation(m.begin(), m.end());
        }
        
        return ans;
    }
};