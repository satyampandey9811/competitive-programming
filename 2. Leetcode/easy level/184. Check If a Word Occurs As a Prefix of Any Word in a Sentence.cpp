// link to question - https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/

class Solution {
public:
    int isPrefixOfWord(string a, string w) {
        int n = w.size(), c = 1;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] == ' ') {
                c++;
                continue;
            }
            if(i-1 >= 0 and a[i-1] == ' ' and a.substr(i, n) == w) return c;
            if(i == 0 and a.substr(i, n) == w) return c; 
        }
        return -1;
    }
};