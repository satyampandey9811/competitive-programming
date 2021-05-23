// link to question - https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/

class Solution {
public:
    bool checkZeroOnes(string s) {
        int c = 1, none = 0, nzero = 0;
        int n = s.size(), one = 0, zero = 0;
        
        if(s[0] == '0') zero++, nzero++;
        else one++, none++;
        
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) {
                c++;
                if(s[i] == '0') zero++;
                else one++;
            }
            else {
                c = 1;
                zero = 0, one = 0;
                if(s[i] == '0') zero = 1;
                else one = 1;
            }
            
            nzero = max(nzero, zero);
            none = max(none, one);
        }
        
        return none > nzero;
    }
};