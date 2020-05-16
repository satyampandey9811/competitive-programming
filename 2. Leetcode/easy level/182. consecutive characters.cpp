// link to question - https://leetcode.com/problems/consecutive-characters/

class Solution {
public:
    int maxPower(string s) {
        int ans = 1, n = s.size();
        int c = 1;
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == s[i+1]) c++;
            else c = 1;
            ans = max(ans, c);
        }
        return ans;
    }
};