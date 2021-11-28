// link to question - https://leetcode.com/problems/removing-minimum-and-maximum-from-array/

class Solution {
public:
    int minimumDeletions(vector<int>& a) {
        int n = a.size();
        int mn = min_element(a.begin(), a.end()) - a.begin();
        int mx = max_element(a.begin(), a.end()) - a.begin();
        
        int ans = INT_MAX;
        if (mx < mn) swap(mn, mx);
        
        ans = min(ans, mn + 1 + n - mx);
        ans = min(ans, mx + 1);
        ans = min(ans, n - mn);
        
        return ans;
    }
};