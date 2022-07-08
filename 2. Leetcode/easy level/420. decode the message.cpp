// link to question - https://leetcode.com/problems/decode-the-message/

class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char, char> m;
        string res;
        vector<bool> a(26);
        char c = 'a';
        
        for (auto &i :key) {
            if (i == ' ') continue;
            if (a[i - 'a']) continue;
            a[i - 'a'] = true;
            m[i] = c++;
        }
        
        for (auto &i :message) {
            if (i == ' ') {
                res += ' ';
            }
            else {
                res += m[i];
            }
        }
        
        return res;
    }
};