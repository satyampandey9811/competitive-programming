// link to question - https://leetcode.com/problems/validate-ip-address/

class Solution {
public:
    string validIPAddress(string a) {
        int dot = 0, colon = 0;
        int n = a.size();
        vector<int> dots = {-1}, colons = {-1};
        int p = -1, q = -1;
        
        for(int i = 0; i < n; i++) {
            if(a[i] == '.') {
                dot++;
                dots.push_back(i - p - 1);
                p = i;
            }
            else if(a[i] == ':') {
                colon++;
                colons.push_back(i - q - 1);
                q = i;
            }
        }
        
        if((dot == 0 and colon == 0) or (dot and colon) or (colon == 0 and dot != 3) or (dot == 0 and colon != 7)) {
            return "Neither";
        }
        if(dot) {            
            dots.push_back(n - p - 1);
            for(int i = 1; i < 5; i++) {
                if(dots[i] < 1 or dots[i] > 3)
                    return "Neither";
            }                
            for(int i = 0; i < n; i++) {
                if(a[i] != '.' and (a[i] < '0' or a[i] > '9'))
                    return "Neither";
            }
            int c = 1;
            for(int i = 0; i < n;) {                
                string y = a.substr(i, dots[c]);
                int x = stoi(y);
                if(y.size() > 1 and y[0] == '0') return "Neither"; 
                if(x > 255) return "Neither";
                i += dots[c] + 1;
                c++;                
            }            
            return "IPv4";
        }          
        colons.push_back(n - q - 1);
        unordered_set<char> z = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','A','B','C','D','E','F',':'};
        for(int i = 0; i < n; i++) {
            if(z.find(a[i]) == z.end())
                return "Neither";                            
        }
        for(int i = 1; i < 9; i++) {
            if(colons[i] < 1 or colons[i] > 4)
                return "Neither";
        }           
        return "IPv6";        
    }
};