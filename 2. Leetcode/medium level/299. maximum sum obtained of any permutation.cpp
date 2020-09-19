// link to question - https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/

class Solution {
public:
    int maxSumRangeQuery(vector<int>& a, vector<vector<int>>& r) {
        int n = a.size(), x, y, ans = 0, mod = 1e9 + 7;
        vector<int> count(n);
        
        for(int i = 0; i < r.size(); i++) {
            x = r[i][0], y = r[i][1];
            count[x]++;
            if(y + 1 < n) count[y+1]--;
        }
        
        for(int i = 1; i < n; i++) count[i] += count[i-1]; 
        
        sort(count.begin(), count.end());
        sort(a.begin(), a.end());
        
        for(int i = 0; i < n; i++) {
            ans = (ans + count[i] * 1LL * a[i]) % mod;
        }
        
        return ans;
    }
};