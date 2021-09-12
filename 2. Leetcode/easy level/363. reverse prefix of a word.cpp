// link to question - https://leetcode.com/problems/reverse-prefix-of-word/

class Solution {
public:
    string reversePrefix(string a, char ch) {
        int n = a.size();
        for(int i = 0; i < n; i++) {
            if(a[i] == ch) {
                reverse(a.begin(), a.begin() + i + 1);
                break;
            }
        }
        return a;
    }
};