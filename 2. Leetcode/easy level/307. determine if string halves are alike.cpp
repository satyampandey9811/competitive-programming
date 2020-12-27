// link to question - https://leetcode.com/problems/determine-if-string-halves-are-alike/

class Solution {
public:
    bool halvesAreAlike(string s) {
        map<char, int> m1, m2;
        int n = s.size();
        
        for(int i = 0; i < n / 2; i++) {
            m1[s[i]]++;
        }
        for(int i = n/2; i < n; i++) {
            m2[s[i]]++;
        }
        
        int c1 = 0, c2 = 0;
        c1 = m1['a'] + m1['e'] + m1['i'] + m1['o'] + m1['u'] + m1['A'] + m1['E'] + m1['I'] + m1['O'] + m1['U'];
        c2 = m2['a'] + m2['e'] + m2['i'] + m2['o'] + m2['u'] + m2['A'] + m2['E'] + m2['I'] + m2['O'] + m2['U'];
        
        return c1 == c2;
    }
};