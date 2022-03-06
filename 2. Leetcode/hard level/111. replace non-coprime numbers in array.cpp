// link to question - https://leetcode.com/problems/replace-non-coprime-numbers-in-array/

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& a) {
        stack<int> s;
        s.push(a[0]);
        int n = a.size();
        
        for (int i = 1; i < n; i++) {
            int top = s.top();
            int gcd = __gcd(top, a[i]);
            
            if (gcd > 1) {
                s.pop();
                int lcm = top * 1LL * a[i] / gcd;
                
                while (s.size() and __gcd(s.top(), lcm) > 1) {
                    lcm = s.top() * 1LL * lcm / __gcd(s.top(), lcm);
                    s.pop();
                }
                
                s.push(lcm);
            }
            else s.push(a[i]);
        }
        
        vector<int> res(s.size());
        int i = s.size() - 1;
        
        while (s.size()) {
            res[i] = s.top();
            i--;
            s.pop();
        }
        
        return res;
    }
};