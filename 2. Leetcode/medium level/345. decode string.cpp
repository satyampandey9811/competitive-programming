// link to question - https://leetcode.com/problems/decode-string/

class Solution {
public:
    string go(int i, int n, string s) {                
        int num = 0, c = 0, si;
        string a;                
        
        for(int j = i; j <= n; j++) {
            if(c == 0 and s[j] >= 'a' and s[j] <= 'z') {
                a += s[j];
                continue;
            }    
            if(c == 0 and s[j] >= '0' and s[j] <= '9') {
                num = num * 10 + s[j] - '0';                
                continue;
            }
            if(s[j] == '[') {
                c++;
                if(c == 1) si = j + 1;
            }
            if(s[j] == ']') {
                c--;
                if(c == 0) {
                    string b = go(si, j - 1, s);
                    for(int k = 0; k < num; k++) a += b;
                    num = 0;
                }
            }
        } 
        
        return a;
    }
    
    string decodeString(string s) {
        return go(0, s.size(), s);
    }
};