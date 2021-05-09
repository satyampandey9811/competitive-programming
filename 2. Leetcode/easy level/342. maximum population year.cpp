// link to question - https://leetcode.com/problems/maximum-population-year/

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& a) {
        int n = a.size(), x = 0;
        int ans;
        
        for(int i = 1950; i <= 2049; i++) {
            int ct = 0;
            for(int j = 0; j < n; j++) {
                if(a[j][0] <= i and a[j][1] > i) {
                    ct++;
                }
            }
            if(ct > x) {
                x = ct;
                ans = i;
            }
        }
        return ans;
    }
};