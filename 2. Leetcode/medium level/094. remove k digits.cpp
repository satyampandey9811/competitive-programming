// link to question - https://leetcode.com/problems/remove-k-digits/

class Solution {
public:
    string removeKdigits(string a, int k) {        
        stack<char> s, r;
        for(int i = 0; i < a.size(); i++) {
            while(k > 0 and s.size() > 0 and s.top() > a[i]) s.pop(), k--;
            s.push(a[i]);
        }
        while(k) s.pop(), k--;        
        while(!s.empty()) r.push(s.top()), s.pop();
        while(r.size() > 0 and r.top() == '0') r.pop();
        if(r.size() == 0) return "0";
        
        string ans;
        while(!r.empty()) ans += r.top(), r.pop();
        return ans;
    }
};