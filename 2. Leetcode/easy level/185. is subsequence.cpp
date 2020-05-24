// link to question - https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0, n = s.size();
        if(n == 0) return 1;
        for(int i = 0; i < t.size(); i++) {
            if(t[i] == s[j]) j++;
            if(j == n) return 1;
        }
        return 0;
    }
};