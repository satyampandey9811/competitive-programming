// link to question - https://leetcode.com/problems/excel-sheet-column-title/

class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        int x;
        while(n > 0){
            x = n % 26;
            if(x)
                ans = char(64 + x) + ans;                                        
            else{
                ans = 'Z' + ans;             
                n--;
            }    
            n /= 26;
        }
        return ans;
    }
};