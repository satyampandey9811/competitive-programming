// link to question - https://leetcode.com/problems/valid-palindrome-ii/

class Solution {
public:
    bool check(int i, int j, string &s) {
        while (i < j) {
            if (s[i] != s[j]) break;
            i++, j--;
        }
        return i >= j;
    }
    
    bool validPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j) {
            if (s[i] != s[j]) break;
            i++, j--;
        }
        if (i < j) {
            if (check(i + 1, j, s)) return true;
            if (check(i, j - 1, s)) return true;
            return false;
        }
        return true;
    }
};