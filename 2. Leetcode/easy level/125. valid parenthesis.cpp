// link to question - https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    
    bool check(char a, char b){
        if(a == '(' and b == ')')
            return true;
        else if(a == '{' and b == '}')
            return true;
        else if(a == '[' and b == ']')
            return true;
        return false;
    }
    
    bool isValid(string s) {
        stack<char> p;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' or s[i] == '{' or s[i] == '[')
                p.push(s[i]);
            else if(s[i] == ')' or s[i] == '}' or s[i] == ']'){
                if(!p.empty() and check(p.top(), s[i])){
                    p.pop();
                }
                else
                    return false;
            }
        }
        return p.empty();
    }
};