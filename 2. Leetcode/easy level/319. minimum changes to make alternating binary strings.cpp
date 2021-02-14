// link to question - https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/

class Solution {
public:
    int minOperations(string s) {
        int a = 0, b = 0, n = s.size();
        
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0 and s[i] == '1') a++;
            if(i & 1 and s[i] == '0') a++;
        }
        
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0 and s[i] == '0') b++;
            if(i & 1 and s[i] == '1') b++;
        }
        
        return min(a, b);
    }
};