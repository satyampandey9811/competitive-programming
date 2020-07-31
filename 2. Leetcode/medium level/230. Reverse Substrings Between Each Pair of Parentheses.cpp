// link to question - https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

class Solution {
public:
    string reverseParentheses(string s) {
        map<int, int> m;
        int n = s.size(), c = 0;
        string ans;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') c++, m[c] = i;
            else if(s[i] == ')') {                
                reverse(s.begin() + m[c], s.begin() + i + 1);
                c--;                
            }
        }
        for(int i = 0; i < n; i++) {
            if(s[i] != '(' and s[i] != ')') ans += s[i];
        }
        return ans;
    }
};