// link to question - https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/

class Solution {
public:
    bool checkString(string s) {
        int n = s.size(), i = 0;
        while (i < n and s[i] == 'a') i++;
        while (i < n and s[i] == 'b') i++;
        return i == n;
    }
};