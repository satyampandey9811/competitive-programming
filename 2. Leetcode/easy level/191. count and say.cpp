// link to question - https://leetcode.com/problems/count-and-say/

class Solution {
public:
    string countAndSay(int n) {
        string s = "1", t;
        for(int i = 2; i <= n; i++){            
            for(int j = 0; j < s.size();) {
                int c = 0;
                int k = j;
                while(k < s.size() and s[j] == s[k]) {
                    c++, k++;
                }
                t = t + to_string(c) + s[j];                
                j = k;
            }
            s = t;      
            t = "";
        }
        return s;
    }
};