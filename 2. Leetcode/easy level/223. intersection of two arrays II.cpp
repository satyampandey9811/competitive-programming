// link to question - https://leetcode.com/problems/intersection-of-two-arrays-ii/

class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        multiset<int> c(a.begin(), a.end());
        vector<int> e;
        for(auto x: b) {         
            auto it = c.find(x);
            if(it != c.end()) {
                e.push_back(x);
                c.erase(it);
            }
        }
        return e;
    }
};