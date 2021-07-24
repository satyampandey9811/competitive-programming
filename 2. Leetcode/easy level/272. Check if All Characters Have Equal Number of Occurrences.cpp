// link to question - https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int n = s.size();
        
        vector<int> c(26);
        
        for(char &i: s) {
            c[i - 'a']++;
        }
        
        int ans = -1;
        
        for(int i = 0; i < 26; i++) {
            if(c[i] == 0) 
                continue;
            if(ans == -1) 
                ans = c[i];
            if(c[i] != ans) 
                return 0;
        }
        
        return 1;
    }
};