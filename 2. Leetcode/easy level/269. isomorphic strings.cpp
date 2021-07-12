// link to question - https://leetcode.com/problems/isomorphic-strings/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> a(256), b(256);
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(a[s[i]] != b[t[i]]) return 0;
            a[s[i]] = b[t[i]] = i + 1;
        }
        return 1;
    }
};