// link to question - https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& a) {
        int n = s.size();
        map<string, string> m;
        string ans;
        
        for(int i = 0; i < a.size(); i++) {
            m[a[i][0]] = a[i][1];
        }
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                int j = i + 1;
                string t;
                while(s[j] != ')') t += s[j++];
                if(m.count(t)) ans += m[t];
                else ans += '?';
                i = j;
            }
            else ans += s[i];
        }
        
        return ans;
    }
};