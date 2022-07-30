// link to question - https://leetcode.com/problems/first-letter-to-appear-twice/

class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> a(26);
        for (auto &i :s) {
            a[i - 'a']++;
            if (a[i - 'a'] > 1) return i;
        }
        return 'a';
    }
};