// link to question - https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string>& a) {
        stack<int> s;
        int n = a.size(), x, y;
        for(int i = 0; i < n; i++) {
            if(a[i] == "+" or a[i] == "-" or a[i] == "*" or a[i] == "/") {
                y = s.top();
                s.pop();
                x = s.top();
                s.pop();
                if(a[i] == "+") s.push(x + y);
                else if(a[i] == "-") s.push(x - y);
                else if(a[i] == "*") s.push(x * y);
                else s.push(x / y);
            }
            else s.push(stoi(a[i]));
        }
        return s.top();
    }
};