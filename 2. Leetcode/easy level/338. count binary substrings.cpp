// link to question - https://leetcode.com/problems/count-binary-substrings/

class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size(), ans = 0;
        if(n == 1) return ans;
        int i = 0, j, c = 1, d = 1;
        
        while(i + 1 < n) {
            if(s[i] == s[i+1]) c++;
            else {
                j = i + 1, d = 0;
                while(j < n and s[j] != s[i] and d < c) {
                    j++, d++;
                }
                ans += min(c, d);
                c = 1;
            }
            i++;
        }
        
        return ans;
    }
};