// link to question - https://leetcode.com/problems/sequential-digits/

class Solution {
public:
    vector<int> sequentialDigits(int start, int end) {
        vector<int> ans;
        string s;
        long long int low = start, l = start, high = end;
        
        while(1) {
            s = to_string(low);
            bool f = false;
            
            if(s[0] == '9') f = true;
            else { 
                for(int i = 1; i < s.size(); i++) {                
                    s[i] = s[i-1] + 1;
                    if(s[i] == '9') {
                        if(i != s.size() - 1) { f = true; break; }
                    }
                }
            }
                                    
            if(s.size() == 10) break;
            if(f) low = pow(10, s.size());            
            else {
                long long int val = stoll(s);
            
                if(val <= high) {
                    if(val >= l) ans.push_back(val);
                }
                else break;
                
                if(s.size() == 9) break;
                
                s[0] = s[0] + 1;
                low = stoll(s);                                            
            }
        }
        
        return ans;
    }
};