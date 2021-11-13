// link to question - https://leetcode.com/problems/check-whether-a-string-contains-another-string/

class Solution {
public:
    bool checkAlmostEquivalent(string a, string b) {
        vector<int> c(26), d(26);
        for(auto i: a) c[i-'a']++;
        for(auto i: b) d[i-'a']++;
        
        for(int i = 0; i < 26; i++) {
            if(abs(c[i] - d[i]) > 3) return 0;
        }
        return 1;
    }
};