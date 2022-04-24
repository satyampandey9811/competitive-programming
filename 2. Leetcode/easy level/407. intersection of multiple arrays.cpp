// link to question - https://leetcode.com/problems/intersection-of-multiple-arrays/

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& a) {
        vector<int> ans;
        map<int, int> m;
        int n = a.size();
        
        for (int i = 0; i < n; i++) {
            for (auto &j :a[i]) m[j]++;
        }
        
        for (auto &i :m) {
            if (i.second == n) ans.push_back(i.first);
        }
        
        return ans;
    }
};