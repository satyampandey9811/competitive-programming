// link to question - https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/

class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        if(n == 1 and s[0] == '?') {
            s[0] = 'a';
            return s;
        }
        
        if(n > 1 and s[0] == '?' and s[1] == '?') s[0] = 'a';
        else if(n > 1 and s[0] == '?') {
            s[0] = (char)(s[1] + 1);
            if(s[0] > 'z') s[0] = 'a';
        }
        
        for(int i = 1; i < n; i++) {
            if(s[i] == '?') {
                s[i] = (char)(s[i - 1] + 1);
                if(s[i] > 'z') s[i] = 'a';
                if(i < n - 1 and s[i] == s[i+1]) {
                    s[i] = (char)(s[i+1] + 1);
                    if(s[0] > 'z') s[0] = 'a';
                }
            }
        }
        
        return s;
    }
};