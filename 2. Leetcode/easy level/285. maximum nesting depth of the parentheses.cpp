// link to question - https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, cur = 0, n = s.size();        
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                cur++;   
                if(cur > ans) ans = cur;
            }
            else if(s[i] == ')') { 
                if(cur > 0) cur--;
                else return -1; 
            } 
        } 
  
        if(cur != 0) return -1; 
        return ans;
    }
};