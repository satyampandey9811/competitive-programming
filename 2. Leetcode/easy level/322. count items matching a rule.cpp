// link to question - https://leetcode.com/problems/count-items-matching-a-rule/

class Solution {
public:
    int countMatches(vector<vector<string>>& a, string rk, string rv) {
        int n = a.size();
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            if(rk == "type" and rv == a[i][0]) ans++;
            else if(rk == "color" and rv == a[i][1]) ans++;
            else if(rk == "name" and rv == a[i][2]) ans++;
        }
        
        return ans;
    }
};