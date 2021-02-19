// link to question - https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

class Solution {
public:
    string minRemoveToMakeValid(string a) {
        string ans;
        int n = a.size(), c = 0;
        stack<int> s;
        
        for(int i = n - 1; i >= 0; i--) {
            if(a[i] == ')') s.push(i);
        }
        
        for(int i = 0; i < n; i++) {
            if(a[i] != '(' and a[i] != ')') {
                ans += a[i];
                continue;
            }
            
            while(s.size() and s.top() <= i) s.pop();
            if(a[i] == '(' and s.size()) {
                ans += a[i];
                c++;
                s.pop();
            }
            else if(a[i] == ')' and c) {
                ans += a[i];
                c--;
            }
        }
        
        return ans;
    }
};