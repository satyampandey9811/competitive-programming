// link to question - https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

class Solution {
public:
    int minAddToMakeValid(string a) {
        int ans = 0, open = 0;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] == '(') open++;
            else {
                if(!open) ans++;
                else open--;
            }
        }
        
        return ans + open;
    }
};