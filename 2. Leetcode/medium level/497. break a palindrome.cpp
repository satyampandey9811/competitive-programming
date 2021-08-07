// link to question - https://leetcode.com/problems/break-a-palindrome/

class Solution {
public:
    string breakPalindrome(string a) {
        int n = a.size();
        if(n == 1) return "";
        
        for(int i = 0; i < n / 2; i++) {
            if(a[i] > 'a') {
                a[i] = 'a';
                return a;
            }
        }
        
        a[n-1] = 'b';
        return a;
    }
};