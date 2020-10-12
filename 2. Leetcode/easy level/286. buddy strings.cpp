// link to question - https://leetcode.com/problems/buddy-strings/

class Solution {
public:
    bool buddyStrings(string a, string b) {
        int m = a.size(), n = b.size();
        if(m != n) return 0;
        
        vector<int> c(26), d(26);
        for(int i = 0; i < n; i++) c[a[i] - 'a']++;
        for(int i = 0; i < n; i++) d[b[i] - 'a']++;
        
        for(int i = 0; i < 26; i++) {
            if(c[i] != d[i]) return 0;
        }
        
        int ct = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] != b[i]) ct++;   
            if(ct > 2) return 0;
        }
        
        if(ct == 1) return 0;
        if(ct == 2) return 1;
        
        for(int i = 0; i < 26; i++) {
            if(c[i] > 1) return 1;
        }
        
        return 0;
    }
};