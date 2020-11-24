// link to question - https://leetcode.com/problems/basic-calculator-ii/

class Solution {
public:
    int calculate(string s) {        
        vector<int> a;
        vector<char> b;
        int n = s.size(), ans = 0;
        string t;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == ' ') continue;
            if(s[i] == '/' or s[i] == '*' or s[i] == '+' or s[i] == '-') {
                a.push_back(stoi(t));
                t = "";
                b.push_back(s[i]);
            }
            else {
                t += s[i];
            }
        }
        if(a.size() == 0 and t == "") return 0;
        a.push_back(stoi(t));
        
        for(int i = 0; i < b.size(); i++) {
            if(b[i] == '*' or b[i] == '/') {
                if(b[i] == '*') a[i] = a[i] * a[i+1];
                else a[i] = a[i] / a[i+1];
                b.erase(b.begin() + i);
                a.erase(a.begin() + i + 1);
                i--;
            }
        }
        ans += a[0];
        for(int i = 0; i < b.size(); i++) {
            if(b[i] == '+') ans += a[i+1];
            else ans -= a[i+1];
        }
        
        return ans;
    }
};