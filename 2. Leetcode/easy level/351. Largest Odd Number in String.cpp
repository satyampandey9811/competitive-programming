// link to question - https://leetcode.com/problems/largest-odd-number-in-string/

class Solution {
public:
    string largestOddNumber(string a) {
        int n = a.size();
        for(int i = n - 1; i >= 0; i--) {
            n = a[i] - '0';
            if(n & 1) return a.substr(0, i + 1);
        }
        return "";
    }
};