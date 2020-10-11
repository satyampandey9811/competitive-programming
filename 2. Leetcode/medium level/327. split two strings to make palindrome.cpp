// link to question - https://leetcode.com/problems/split-two-strings-to-make-palindrome/

class Solution {
public:
    bool go(string& a, int i, int j) {
        while(i <= j and a[i] == a[j]) {
            i++, j--;
        }
        return i > j;
    }
    
    bool check(string &a, string& b) {
        int n = a.size();
        int i = 0, j = n - 1;
        while(i < n and a[i] == b[j]) {
            i++, j--;
        }
        if(i == n) return 1;
        if(go(a, i, j)) return 1;        
        return go(b, i, j);
    }
    bool checkPalindromeFormation(string a, string b) {    
        if(check(a, b)) return 1;                
        return check(b, a);
    }
};