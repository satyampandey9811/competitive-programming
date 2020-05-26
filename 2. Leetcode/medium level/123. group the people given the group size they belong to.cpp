// link to question - https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& a) {
        vector<vector<int>> ans;
        vector<pair<int, int>> g;
        int n = a.size();
        for(int i = 0; i < n; i++) {
            g.push_back({a[i], i});
        }
        sort(g.begin(), g.end());
        
        vector<int> temp;
        
        for(int i = 0; i < g.size(); i++) {
            temp.push_back(g[i].second);
            if(temp.size() == g[i].first) {
                ans.push_back(temp);
                temp = {};
            }
        }
        return ans;
    }
};