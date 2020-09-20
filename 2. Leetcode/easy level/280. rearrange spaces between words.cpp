// link to question - https://leetcode.com/problems/rearrange-spaces-between-words/

class Solution {
public:
    string reorderSpaces(string a) {
        string ans;
        int n = a.size();
        
        int space = 0, words = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] == ' ') space++;
        }
        
        for(int i = 0; i < n; i++) {
            if(i < n - 1 and a[i] != ' ' and a[i+1] == ' ') words++;
            if(i == n - 1 and a[i] != ' ') words++;
        }
        
        if(words == 1) {
            string temp;
            for(int i = 0; i < n; i++) {
                if(a[i] != ' ') temp += a[i];
                if(i < n - 1 and a[i] != ' ' and a[i+1] == ' ') {  
                    ans += temp;
                    temp = "";                    
                    break;
                }
                if(i == n - 1 and a[i] != ' ') {                    
                    ans += temp;
                    break;
                }
            }              
            for(int j = 0; j < space; j++) ans += ' ';
            
            return ans;
        }            
        
        int c = space / (words - 1);
        int r = space % (words - 1);
                
        string temp;
        int w = 0;
        
        for(int i = 0; i < n; i++) {
            if(a[i] != ' ') temp += a[i];
            if(i < n - 1 and a[i] != ' ' and a[i+1] == ' ') {          
                ans += temp;
                temp = "";
                w++;
                
                if(w != words) { for(int j = 0; j < c; j++) ans += ' '; }
            }
            if(i == n - 1 and a[i] != ' ') {                
                ans += temp;
            }
        }
        
        for(int j = 0; j < r; j++) ans += ' ';
        
        return ans;
    }
};