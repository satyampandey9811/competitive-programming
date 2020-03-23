// link to question - https://leetcode.com/problems/print-words-vertically/

class Solution {
public:
    vector<string> printVertically(string s) {        
        int ct = 0, ml = 0, n = s.size(), z, k;
        vector<string> ans;
        
        for(int i = 0; i < n; i++){
            ct++;            
            if(s[i] == ' ')                
                ct = 0;            
            ml = max(ct, ml);
        }
        
        vector<vector<char>> a(ml);
        ct = 0;
        for(int i = 0; i < n; i++){
            a[ct].push_back(s[i]);
            ct++;
            
            if(i + 1 < n and s[i + 1] == ' '){
                z = ml - ct;
                while(z){
                    a[ct].push_back(' ');
                    ct++;
                    z--;
                }
                ct = 0;
                i++;
            }
        }
        
        for(int i = 0; i < a.size(); i++){
            string res;            
            
            for(k = a[i].size() - 1; k >= 0; k--){
                if(a[i][k] != ' ') break;
            }
            for(int j = 0; j <= k; j++) res += a[i][j];           
            
            ans.push_back(res);
        }
        
        return ans;
    }
};