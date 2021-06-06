// link to question - https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/

class Solution {
public:
    int reductionOperations(vector<int>& a) {
        int n = a.size(), ans = 0;
        map<int, int> m;
        
        for(int i = 0; i < n; i++) m[a[i]]++;
        
        while(m.size() > 1) {
            int x = m.rbegin() -> first;
            int y = m.rbegin() -> second;
            ans += y;
            m.erase(x);
            m.rbegin() -> second += y;
        }
        
        return ans;
    }
};