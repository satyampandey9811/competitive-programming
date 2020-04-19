// link to question - https://leetcode.com/problems/reformat-the-string/

class Solution {
public:
    string reformat(string s) {
        int cd = 0, ca = 0;
        string a, d;
        
        for(auto x: s){
            if(isalpha(x)) 
                a += x, ca++;
            else
                d += x, cd++;            
        }
        if(abs(cd - ca) > 1) return "";
        string ans;
                
        for(int i = 0, j = 0; i < a.size(); i++, j++){            
            ans += a[i];
            if(j < d.size())
                ans += d[j];
        }        
        
        if(cd > ca) ans = d[cd - 1] + ans;
    
        return ans;
    }
};