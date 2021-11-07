// link to question - https://leetcode.com/problems/count-vowel-substrings-of-a-string/

class Solution {
public:
    int countVowelSubstrings(string a) {
        int n = a.size();
        int ans = 0;
        set<char> s = {'a', 'e', 'i', 'o', 'u'};
        set<char> t;
        
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(s.count(a[j]) < 1) break;
                t.insert(a[j]);
                if((int)t.size() == 5) ans++;
            }
            t.clear();
        }
        
        return ans;
    }
};