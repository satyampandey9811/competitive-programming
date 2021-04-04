// link to question - https://leetcode.com/problems/finding-the-users-active-minutes/

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& a, int k) {
        map<int, set<int>> m;
        int n = a.size();
        vector<int> ans(k);
        
        for(int i = 0; i < n; i++) {
            m[a[i][0]].insert(a[i][1]);
        }
        
        for(auto &i: m) {
            ans[i.second.size() - 1]++;
        }
        
        return ans;
    }
};