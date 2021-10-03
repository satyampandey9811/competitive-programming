// link to question - https://leetcode.com/problems/minimum-moves-to-convert-string/

class Solution {
public:
    int minimumMoves(string s) {
        int l = 0, r = 0, n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] == 'X') {
                l++;
                i += 2;
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == 'X') {
                r++;
                i -= 2;
            }
        }
        
        return min(l, r);
    }
};