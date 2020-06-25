// link to question - https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string a) {        
        int n = a.size();        
        vector<string> b;
        string s, ans;
        
        for(int i = 0; i < n; i++){        
            if(a[i] != ' '){
                s += a[i];
                if(i == n-1){
                    b.push_back(s);
                    break;
                }
                if(a[i+1] == ' ')
                    b.push_back(s);                                    
            }
            else 
                s = "";            
        }
        
        for(int i = b.size() - 1; i >= 0; i--){
            ans += b[i];                        
            if(i)
                ans += ' ';
        }
        return ans;
    }
};