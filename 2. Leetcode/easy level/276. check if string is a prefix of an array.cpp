// link to question - https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/

class Solution {
public:
    bool isPrefixString(string s, vector<string>& a) {
        string ans;
        int n = a.size();
        for(int i = 0; i < n; i++) {
            ans += a[i];
            if(s == ans) return 1;
        }
        return 0;
    }
};