// link to question - https://leetcode.com/problems/move-pieces-to-obtain-a-string/

class Solution {
public:
    bool canChange(string s, string t) {
        int n = s.size();
        int i = 0, j = 0;
        
        while (i < n and j < n) {
            if (s[i] == '_') {
                i++;
                continue;
            }
            if (t[j] == '_') {
                j++;
                continue;
            }
            if (s[i] != t[j]) return 0;
            i++, j++;
        }
        while (i < n and s[i] == '_') i++;
        while (j < n and t[j] == '_') j++;
        
        if (i < n or j < n) return 0;
        
        int l = 0, r = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L' and l) {
                l--;
                s[i] = '_';
            }
            if (s[i] == '_' and r) {
                r--;
                s[i] = 'R';
            }
            if (s[i] == t[i]) continue;
            if (s[i] == 'L' and t[i] == '_') return 0;
            if (s[i] == '_' and t[i] == 'R') return 0;
            
            if (t[i] == 'L') l++;
            else r++;
        }
        
        return 1;
    }
};