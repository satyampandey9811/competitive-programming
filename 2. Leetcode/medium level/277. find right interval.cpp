// link to question - https://leetcode.com/problems/find-right-interval/

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& a) {
        int n = a.size();
        vector<int> ans(n);
        set<pair<int, int>> s;
        
        for(int i = 0; i < n; i++) {
            s.insert({a[i][0], i});
        }
        
        for(int i = 0; i < n; i++) {
            auto it = s.lower_bound({a[i][1], 0});
            if(it == s.end()) ans[i] = -1;
            else ans[i] = (*it).second;
        }
        
        return ans;
    }
};