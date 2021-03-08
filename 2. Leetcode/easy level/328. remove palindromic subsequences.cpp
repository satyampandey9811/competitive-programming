// link to question - https://leetcode.com/problems/remove-palindromic-subsequences/

class Solution {
public:
    int removePalindromeSub(string s) {
        int n = s.size();
        if(n == 0) return 0;
        int i = 0, j = n - 1;
        while(i < j) {
            if(s[i] == s[j]) i++, j--;
            else break;
        }
        if(i >= j) return 1;
        return 2;
    }
};