// link to question - https://leetcode.com/problems/determine-if-two-strings-are-close/

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return 0;
        
        vector<int> a(26), b(26);
        for(auto& i: word1) a[i-'a']++;
        for(auto& i: word2) b[i-'a']++;

        for(int i = 0; i < 26; i++) {
            if((!a[i] and b[i]) or (a[i] and !b[i])) return 0;
        }
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        for(int i = 0; i < 26; i++) {
            if(a[i] != b[i]) return 0;
        }
        return 1;
    }
};