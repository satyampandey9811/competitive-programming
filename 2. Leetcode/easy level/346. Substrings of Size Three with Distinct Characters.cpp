// link to question - https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/

class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size(), ans = 0;
        if(n < 3) return ans;
        for(int i = 0; i < n - 2; i++) {
            if(s[i] != s[i+1] and s[i] != s[i+2] and s[i+1] != s[i+2]) ans++;
        }
        return ans;
    }
};