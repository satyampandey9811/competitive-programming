// link to question - https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/

class Solution {
public:
    string freqAlphabets(string s) {
        int n = s.size(), num;
        string ans;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '#'){
                num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0'); 
                i -= 2;
            }
            else 
                num = s[i] - '0';
            ans = (char)(96 + num) + ans;
        }
        return ans;
    }
};