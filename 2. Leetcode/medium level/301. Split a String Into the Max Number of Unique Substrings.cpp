// link to question - https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/

class Solution {
public:
    int n;    
    
    int go(int pos, string& a, unordered_set<string> s) {
        if(pos == n) return 0;                                
        
        int ans = 0;
        string t;
        
        for(int i = pos; i < n; i++) {
            t += a[i];
            if(s.count(t) == 0) {
                s.insert(t);
                ans = max(ans, 1 + go(i + 1, a, s));
                s.erase(t);
            }
        }
        
        return ans;
    }
    
    int maxUniqueSplit(string a) {
        ios::sync_with_stdio(false), cin.tie(0);
        unordered_set<string> s;
        n = a.size();                
        return go(0, a, s);        
    }
};