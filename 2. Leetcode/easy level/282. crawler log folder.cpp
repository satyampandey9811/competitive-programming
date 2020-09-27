// link to question - https://leetcode.com/problems/crawler-log-folder/

class Solution {
public:
    int minOperations(vector<string>& a) {
        stack<string> s;
        int n = a.size();        
        
        for(int i = 0; i < n; i++) {            
            if(a[i][0] == '.' and a[i][1] == '/') continue;
            if(a[i][0] != '.') s.push(a[i]);        
            else { if(s.size()) s.pop(); }
        }
        
        return s.size();
    }
};