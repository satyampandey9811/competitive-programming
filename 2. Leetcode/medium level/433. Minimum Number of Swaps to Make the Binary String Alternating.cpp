// link to question - https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/

class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int one = 0, zero = 0, x, y;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') zero++;
            else one++;
        }
        
        if((one > n / 2 or zero > n / 2) and n % 2 == 0) return -1;
        if((one > n / 2 + 1 or zero > n / 2 + 1) and n % 2) return -1;
        
        if(n % 2 == 0) {
            x = 0, y = 0;
            for(int i = 0; i < n; i++) {
                if(i % 2 == 0 and s[i] == '0') x++;
                else if(i % 2 and s[i] == '1') x++;
            }
            for(int i = 0; i < n; i++) {
                if(i % 2 == 0 and s[i] == '1') y++;
                else if(i % 2 and s[i] == '0') y++;
            }
            return (n - max(x, y)) / 2;
        }
        
        if(zero < one) {
            x = 0;
            for(int i = 0; i < n; i++) {
                if(i % 2 == 0 and s[i] == '1') x++;
                else if(i % 2 and s[i] == '0') x++;
            }
            return (n - x) / 2;
        }
        
        x = 0;
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0 and s[i] == '0') x++;
            else if(i % 2 and s[i] == '1') x++;
        }
        
        return (n - x) / 2;
    }
};