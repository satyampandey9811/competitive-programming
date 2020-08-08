// link to question - https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int c = 0;
        int ans = 0;
        
        for(int i = 0; i < n;) {
            if(s[i] == '(') c++, i++;
            else if(s[i] == ')') {
                if(i + 1 < n and s[i+1] == ')') {
                    if(c == 0) ans++;
                    else c--;
                    i += 2;
                }
                else {
                    ans++;
                    if(c == 0) ans++;
                    else c--;
                    i++;
                }
            } 
        }
        
        if(c) ans += c * 2;
        
        return ans;
    }
};