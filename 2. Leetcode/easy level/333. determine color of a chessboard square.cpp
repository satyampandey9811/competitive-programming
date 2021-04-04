// link to question - https://leetcode.com/problems/determine-color-of-a-chessboard-square/

class Solution {
public:
    bool squareIsWhite(string s) {
        int a = s[0] - 'a', b = s[1] - '1';
        if(a % 2 == 0 and b % 2 == 0) return 0;
        if(a & 1 and b & 1) return 0;
        return 1;
    }
};