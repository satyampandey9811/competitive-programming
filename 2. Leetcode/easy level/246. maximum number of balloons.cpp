// link to question - https://leetcode.com/problems/maximum-number-of-balloons/

class Solution {
public:
    int maxNumberOfBalloons(string s) {
        int a = 0, b = 0, l = 0, o = 0, n = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'a') a++;
            else if(s[i] == 'b') b++;
            else if(s[i] == 'l') l++;
            else if(s[i] == 'o') o++;
            else if(s[i] == 'n') n++;
        }
        int ans = INT_MAX;
        ans = min({ans, a, b, n, l / 2, o / 2});
        return ans;
    }
};