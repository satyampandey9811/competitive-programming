// link to question - https://leetcode.com/problems/word-pattern/

class Solution {
public:
    bool wordPattern(string pat, string s) {                            
        unordered_map<char, string> mp;
        unordered_map<string, char> mq;
        vector<string> words;
        int m = pat.size(), n = s.size();
        
        string temp;
        for(int i = 0; i < n; i++) {
            if(s[i] == ' ') {
                words.push_back(temp);
                temp = "";
                continue;
            }
            temp += s[i];
        }
        words.push_back(temp);
        
        if(words.size() != m) return 0;
        
        for(int i = 0; i < m; i++) {
            if(mp.count(pat[i])) {
                if(mp[pat[i]] != words[i]) return 0;
            }
            else if(mq.count(words[i])) {
                if(mq[words[i]] != pat[i]) return 0;
            }
            else {
                mp[pat[i]] = words[i];
                mq[words[i]] = pat[i];
            }
        }
        
        return 1;
    }
};