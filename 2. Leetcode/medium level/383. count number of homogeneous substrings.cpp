// link to question - https://leetcode.com/problems/count-number-of-homogenous-substrings/

class Solution {
public:    
    int countHomogenous(string s) {
        int mod = 1e9 + 7;
        int ans = 0, n = s.size();
        
        for(int i = 0; i < n; i++) {
            int len = 1, c = 1;
            int j = i + 1;
            while(j < n and s[j] == s[i]) {
                j++;
                c++;
                len = (len + c) % mod;
            }
            
            ans = (ans + len) % mod;
            i = j - 1;
        }
        
        return ans;
    }
};