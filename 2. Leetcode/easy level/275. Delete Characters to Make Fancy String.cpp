// link to question - https://leetcode.com/problems/delete-characters-to-make-fancy-string/

class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        string ans;
        ans += s[0];
        if(n > 1) ans += s[1];
        
        for(int i = 2; i < n; i++) {
            if(s[i] == ans[(int)ans.size() - 1] and s[i] == ans[(int)ans.size() - 2]) continue;
            ans += s[i];
        }
        
        return ans;
    }
};