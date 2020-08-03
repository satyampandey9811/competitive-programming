// link to question - https://leetcode.com/problems/zigzag-conversion/

class Solution {
public:
    string convert(string s, int nr) {
        if(nr == 1) return s;
        string ans;
        int n = s.size();
        
        for(int i = 0; i < nr; i++) {
            int step1 = (nr - i - 1) * 2;
            int step2 = i * 2;
            int pos = i;
            if(pos < n) ans += s[pos];
            
            while(1) {
                pos += step1;
                if(pos >= n) break;
                if(step1) ans += s[pos];
                
                pos += step2;
                if(pos >= n) break;
                if(step2) ans += s[pos];
            }
        }
        
        return ans;
    }
};