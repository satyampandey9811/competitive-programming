// link to question - https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    vector<string> ans;

    void go(int open, string temp, int n) {
        if(n == 0) {
            for(int i = 0; i < open; i++) temp += ')';
            ans.push_back(temp);        
            return;
        }
        
        if(open == 0) {
            temp += '(';
            go(open + 1, temp, n - 1);
        }
        else {
            temp += '(';
            go(open + 1, temp, n - 1);
            temp.pop_back();
            temp += ')';
            go(open - 1, temp, n);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string temp;
        go(0, temp, n);
        return ans;    
    }
};