// link to question - https://leetcode.com/problems/decode-ways/

class Solution {
public:    
    int numDecodings(string s) {     
        if(s[0] == '0') return 0;
        int n = s.size();  
        
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == '0' and s[i+1] == '0') return 0;
        }
        
        vector<int> a(n);
        
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '0') {
                if(i - 1 >= 0) {
                    a[i-1] = 1;
                    if(i + 1 < n) a[i-1] = a[i+1];
                }
            }
            else {
                if(i == n - 1) a[i] = 1;
                else {
                    a[i] = a[i+1];
                    string t = s.substr(i, 2);                    
                    if(stoi(t) <= 26) {
                        if(i + 2 == n) a[i]++;
                        else a[i] += a[i+2];
                    }
                }
            }
        }   
        
        return a[0];
    }    
};