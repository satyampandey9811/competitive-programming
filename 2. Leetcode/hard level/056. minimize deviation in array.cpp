// link to question - https://leetcode.com/problems/minimize-deviation-in-array/

class Solution {
public:
    int minimumDeviation(vector<int>& a) {
        int n = a.size();
        set<int> s;
        for(auto& i: a) s.insert(i & 1 ? i * 2 : i);
        
        int ans = *s.rbegin() - *s.begin();
        int x, y;
        
        while(*s.rbegin() % 2 == 0) {
            
            s.insert(*s.rbegin() / 2);
            s.erase(*s.rbegin());
            ans = min(ans, *s.rbegin() - *s.begin());
        }
        
        return ans;
    }
};