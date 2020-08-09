// link to question - https://leetcode.com/problems/make-the-string-great/

class Solution {
public:
    string makeGood(string a) {
        int n = a.size();
        stack<char> s;        
        string ans;
        
        for(int i = 0; i < n; i++) {
            if(s.size() and (s.top() == a[i] + 32 or a[i] == s.top() + 32)) {
                s.pop();
            }
            else s.push(a[i]);
        }
        while(s.size() != 0) {
            ans += s.top();
            s.pop();
        }
        if(ans.size()) reverse(ans.begin(), ans.end());
        
        return ans;
    }
};