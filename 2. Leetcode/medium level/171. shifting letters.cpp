// link to question - https://leetcode.com/problems/shifting-letters/

class Solution {
public:
    string shiftingLetters(string s, vector<int>& a) {
        int n = s.size();
        a[n-1] %= 26;
        
        for(int i = n - 2; i >= 0; i--) {
            a[i] += a[i+1];
            a[i] %= 26;
        }
        
        for(int i = 0; i < n; i++) {
            s[i] = (char)(97 + (s[i] - 'a' + a[i]) % 26);
        }
        
        return s;
    }
};