// link to question - https://leetcode.com/problems/check-if-the-sentence-is-pangram/

class Solution {
public:
    bool checkIfPangram(string a) {
        vector<int> s(26);
        int n = a.size();
        for(int i = 0; i < n; i++) {
            s[a[i] - 'a']++;
        }
        
        for(int i = 0; i < 26; i++) {
            if(s[i] == 0) return 0;
        }
        return 1;
    }
};