// link to question - https://leetcode.com/problems/validate-stack-sequences/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int n = pushed.size();
        
        int i = 0, j = 0;
        while(i < n) {
            if(s.size() and s.top() == popped[j]) {
                s.pop();
                j++;
                continue;
            }
            if(pushed[i] != popped[j])
                s.push(pushed[i]);
            else j++;
            i++;
        }
        
        while(s.size()) {
            if(s.top() == popped[j]) {
                s.pop();
                j++;
            }
            else return 0;
        }
        
        return 1;
    }
};