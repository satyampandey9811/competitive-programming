// link to question - https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return 0;
        
        vector<int> a(26);
        
        for(int i = 0; i < s.size(); i++) {
            a[s[i] - 'a']++;
            a[t[i] - 'a']--;
        }                            
        
        for(int i = 0; i < 26; i++) {
            if(a[i])
                return 0;
        }
        return 1;
    }
};