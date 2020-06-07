// link to question - leetcode.com/problems/shuffle-the-array/

class Solution {
public:
    vector<int> shuffle(vector<int>& a, int n) {
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            ans.push_back(a[i]);
            ans.push_back(a[i+n]);
        }
        return ans;
    }
};