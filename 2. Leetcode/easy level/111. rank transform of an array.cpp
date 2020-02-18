// link to question - https://leetcode.com/problems/rank-transform-of-an-array/

class Solution {
public:    
    vector<int> arrayRankTransform(vector<int>& a) {
        vector<int> ans;
        set<int> s(a.begin(), a.end());
        vector<int> b(s.begin(), s.end());        
        for(int i = 0; i < a.size(); i++){
            int x = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            ans.push_back(x + 1);
        }
        return ans;
    }
};