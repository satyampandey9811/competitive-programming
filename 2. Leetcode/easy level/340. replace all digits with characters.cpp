// link to question - https://leetcode.com/problems/replace-all-digits-with-characters/

class Solution {
public:
    string replaceDigits(string s) {
        int n = s.size();
        for(int i = 1; i < n; i += 2) {
            s[i] = char(s[i-1] + (s[i] - '0'));
        }
        return s;
    }
};