// link to question - https://leetcode.com/problems/integer-to-roman/

class Solution {
public:
    string intToRoman(int n) {
        string ans;
        vector<int> a = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        vector<string> b = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        
        int i = 12;
        while(n) {
            if(n >= a[i]) {
                ans += b[i];
                n -= a[i];
            }
            else i--;
        }
        
        return ans;
    }
};