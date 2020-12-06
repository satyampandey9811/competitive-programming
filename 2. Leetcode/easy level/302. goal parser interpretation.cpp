// link to question - https://leetcode.com/problems/goal-parser-interpretation/

class Solution {
public:
    string interpret(string a) {
        string ans;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] == 'G') ans += 'G';
            else if(a[i] == '(' and a[i+1] == ')') ans += 'o', i++;
            else ans += "al", i += 3;
        }
        return ans;
    }
};