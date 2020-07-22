// link to question - https://leetcode.com/problems/avoid-flood-in-the-city/

class Solution {
public:
    vector<int> avoidFlood(vector<int>& a) {
        int n = a.size(), x;
        vector<int> ans(n, 1);
        unordered_map<int, int> m;
        set<int> s;
        
        for(int i = 0; i < n; i++) {
            if(a[i] == 0) s.insert(i);
            else {
                if(m.count(a[i])) {
                    x = m[a[i]];
                    auto it = s.upper_bound(x);
                    if(it == s.end()) return {};
                    ans[*it] = a[i];
                    s.erase(it);                    
                }
                m[a[i]] = i;
                ans[i] = -1;
            }
        }
        
        return ans;
    }
};