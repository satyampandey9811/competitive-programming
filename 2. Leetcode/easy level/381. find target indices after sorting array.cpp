// link to question - https://leetcode.com/problems/find-target-indices-after-sorting-array/

class Solution {
public:
    vector<int> targetIndices(vector<int>& a, int t) {
        vector<int> ans;
        int n = a.size();
        sort(a.begin(), a.end());
        
        for (int i = 0; i < n; i++) {
            if (a[i] == t) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};