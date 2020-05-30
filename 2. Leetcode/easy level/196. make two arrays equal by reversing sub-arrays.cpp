// link to question - https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/

class Solution {
public:
    bool canBeEqual(vector<int>& t, vector<int>& a) {
        unordered_set<int> s(t.begin(), t.end());
        for(int i = 0; i < a.size(); i++) {
            if(s.count(a[i]) == 0) return 0;
        }
        return 1;
    }
};