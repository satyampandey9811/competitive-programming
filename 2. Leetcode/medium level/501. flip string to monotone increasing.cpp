// link to question - https://leetcode.com/problems/flip-string-to-monotone-increasing/

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size(), ans = 1e6;
        vector<int> one(n + 2), zero(n + 2);
        
        for(int i = 1; i <= n; i++) {
            if(s[i-1] == '1') one[i] = 1;
            one[i] += one[i-1];
        }
        for(int i = n; i > 0; i--) {
            if(s[i-1] == '0') zero[i] = 1;
            zero[i] += zero[i+1];
        }
        
        for(int i = 1; i <= n + 1; i++) {
            ans = min(ans, one[i-1] + zero[i]);
        }
        return ans;
    }
};