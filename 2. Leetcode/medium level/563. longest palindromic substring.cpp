// link to question - https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    int n, mx = 1, left = 0, j, k;
    
    void check (string &s) {
        while (j >= 0 and k < n) {
            if (s[j] != s[k]) break;
            if (k - j + 1 > mx) {
                mx = k - j + 1;
                left = j;
            }
            j--, k++;
        }
    }
    
    string longestPalindrome(string s) {
        n = s.size();
        
        for (int i = 0; i < n; i++) {
            j = i - 1, k = i + 1;
            check(s);
            j = i, k = i + 1;
            check(s);
        }
        
        return s.substr(left, mx);
    }
};