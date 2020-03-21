// link to question - https://leetcode.com/problems/remove-outermost-parentheses/

class Solution {
public:
    string removeOuterParentheses(string a) {
        string ans;
        int n = a.size(), no = 0, nc = 0;
        
        for(int i = 0; i < n; i++){
            if(a[i] == '(' and no == 0 and nc == 0){
                no++;
                continue;
            }            
            if(a[i] == '(') 
                no++;
            else nc++;                            
            
            if(no == nc) 
                no = nc = 0;
            else 
                ans += a[i];
        }
        
        return ans;
    }
};