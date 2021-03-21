// link to question - https://leetcode.com/problems/second-largest-digit-in-a-string/

class Solution {
public:
    int secondHighest(string s) {
        int n = s.size(), ans = -1, sl = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] >= '0' and s[i] <= '9') {
                if(s[i] - '0' > ans) {
                    sl = ans;
                    ans = s[i] - '0';
                }
                else if(s[i] - '0' < ans) sl = max(sl, s[i] - '0');
            }
        }
        
        return sl;
    }
};