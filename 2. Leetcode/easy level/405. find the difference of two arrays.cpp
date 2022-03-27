// link to question - https://leetcode.com/problems/find-the-difference-of-two-arrays/

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        set<int> a, b;
        for (auto &i :nums1) a.insert(i);
        for (auto &i :nums2) b.insert(i); 
        
        for (auto &i :a) {
            if (b.count(i) < 1) ans[0].push_back(i);
        }
        for (auto &i :b) {
            if (a.count(i) < 1) ans[1].push_back(i);
        }
        
        return ans;
    }
};