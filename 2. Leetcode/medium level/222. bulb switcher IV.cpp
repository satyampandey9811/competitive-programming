// link to question - https://leetcode.com/problems/bulb-switcher-iv/

class Solution {
public:
    int minFlips(string t) {
        int n = t.size();
        int ans = 0, s = 0;
        
        for(int i = 0; i < n; i++) {
            if(t[i] == '0' and s) {
                ans++;
                s = 0;
            }   
            else if(t[i] == '1' and !s) {
                ans++;
                s = 1;
            }
        }
        return ans;
    }
};