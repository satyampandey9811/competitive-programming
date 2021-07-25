// link to question - https://leetcode.com/problems/sum-of-digits-of-string-after-convert/

class Solution {
public:
    int getLucky(string s, int k) {
        int ans = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            int x = s[i] - 'a' + 1;
            while(x > 0) {
                ans += x % 10;
                x /= 10;
            }
        }
        k--;
        
        for(int i = 0; i < k; i++) {
            int x = ans;
            ans = 0;
            while(x > 0) {
                ans += x % 10;
                x /= 10;
            }
        }
        
        return ans;
    }
};