// link to question - https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size(), ans = 1;
        int c = 1;
        
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1] + 1) c++;
            else c = 1;
            ans = max(ans, c);
        }
        
        return ans;
    }
};