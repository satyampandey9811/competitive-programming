// link to question - https://leetcode.com/problems/maximum-value-after-insertion/

class Solution {
public:
    string maxValue(string s, int x) {
        string res;
        int n = s.size();
        
        if(s[0] != '-') {
            bool f = true;
            
            for(int i = 0; i < n; i++) {
                
                if(s[i] - '0' < x) {
                    f = false;
                    res += to_string(x);
                    res += s.substr(i);
                    break;
                }
                res += s[i];
            }
            
            if(f) res += to_string(x);
        }
        else {
            res = "-";
            bool f = true;
            
            for(int i = 1; i < n; i++) {
                
                if(s[i] - '0' > x) {
                    f = false;
                    res += to_string(x);
                    res += s.substr(i);
                    break;
                }
                res += s[i];
            }
            
            if(f) res += to_string(x);
        }
        
        return res;
    }
};