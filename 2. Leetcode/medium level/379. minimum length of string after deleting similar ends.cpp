// link to question - https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/

class Solution {
public:
    int minimumLength(string s) {
        int ans = 0, n = s.size();
        
        int i = 0, j = n - 1;
        
        while(i < j) {
            if(s[i] != s[j]) break;
            int k = i + 1, l = j - 1;
            ans += 2;
            while(k < j) {
                if(s[k] != s[i]) break;                
                k++;
                ans++;
            }
            while(l > k) {
                if(s[l] != s[j]) break;                
                l--;
                ans++;
            }
            i = k, j = l;
        }
        
        return n - ans;
    }
};