// link to question - https://leetcode.com/problems/valid-parenthesis-string/

class Solution {
public:
    bool checkValidString(string a) {
        int n = a.size() - 1;
        int x = 0, y = 0;
        
        for(int i = 0; i <= n; i++){
            if(a[i] == '*' or a[i] == '(') x++;
            else x--;
            
            if(a[n - i] == '*' or a[n - i] == ')') y++;
            else y--;
            
            if(x < 0 or y < 0) return false;
        }
        return true;
    }
};