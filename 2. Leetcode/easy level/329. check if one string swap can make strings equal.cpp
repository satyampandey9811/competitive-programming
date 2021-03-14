// link to question - https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size(), c = 0;
        vector<char> a, b;
        
        for(int i = 0; i < n; i++) {
            if(s1[i] != s2[i]) {
                c++;
                a.push_back(s1[i]);
                b.push_back(s2[i]);
            }
        }
        
        if(c == 0 or (c == 2 and a[0] == b[1] and a[1] == b[0]))  return 1;
        return 0;
    }
}