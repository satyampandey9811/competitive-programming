// link to question - https://leetcode.com/problems/sorting-the-sentence/

class Solution {
public:
    string sortSentence(string s) {
        string ans, t;
        int n = s.size();
        map<int, string> m;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == ' ') continue;
            if(s[i] > '0' and s[i] <= '9') {
                m[s[i] - '0'] = t;
                t = "";
            }
            else t += s[i];
        }
        m[s[s.back() - '0']] = t;
        
        for(auto &i: m) {
            ans += i.second;
            ans += " ";
        }
        
        ans.pop_back();
        ans.pop_back();
        return ans;
    }
};