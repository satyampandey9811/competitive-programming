// link to question - https://leetcode.com/problems/find-the-difference/

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> c(26);
        for(int i = 0; i < t.size(); i++) c[t[i] - 'a']++;
        for(int i = 0; i < s.size(); i++) c[s[i] - 'a']--;
        for(int i = 0; i < 26; i++) {
            if(c[i]) return (char)(97 + i);
        }
        return 'c';
    }
};