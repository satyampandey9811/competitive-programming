// link to question - https://leetcode.com/problems/random-pick-with-weight/

class Solution {
public:
    vector<int> s;
    Solution(vector<int> w) {
        for (int i : w) s.push_back(s.empty() ? i : (i + s.back()));
    }
    
    int pickIndex() {
        int m = s.back();
        int r = rand() % m;
        return upper_bound(s.begin(), s.end(), r) - s.begin();        
    }
};