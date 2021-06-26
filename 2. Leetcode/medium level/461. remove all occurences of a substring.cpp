// link to question - https://leetcode.com/problems/remove-all-occurrences-of-a-substring/

class Solution {
public:
    string removeOccurrences(string a, string part) {
        string s = a;
        int m = part.size();
        while(s.find(part) != string::npos) {
            int f = s.find(part);
            s = s.substr(0, f) + s.substr(f + m);
        }
        return s;
    }
};