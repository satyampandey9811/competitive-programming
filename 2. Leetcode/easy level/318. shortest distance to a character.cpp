// link to question - https://leetcode.com/problems/shortest-distance-to-a-character/

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        set<int> st;
        int n = s.size(), d;
        vector<int> ans(n);        
        
        for(int i = 0; i < n; i++) {
            if(s[i] == c) st.insert(i);    
        }
        
        for(int i = 0; i < n; i++) {
            auto l = st.lower_bound(i);
            auto u = st.upper_bound(i);            
            
            if(l != st.end() and *l == i) {
                ans[i] = 0;
            }
            else {
                if(l != st.begin()) l--;
                if(u == st.end()) u--;                
                ans[i] = min(abs(i - *l), abs(i - *u));
            }
        }
        
        return ans;
    }
};