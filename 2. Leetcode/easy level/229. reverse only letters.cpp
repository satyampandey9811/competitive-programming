// link to question - https://leetcode.com/problems/reverse-only-letters/

class Solution {
public:
    string reverseOnlyLetters(string a) {
        
        int i = 0, j = a.size() - 1;
        while(i < j){
            if(isalpha(a[i]) and isalpha(a[j])){
                swap(a[i], a[j]);
                i++, j--;
            }
            else if(isalpha(a[i]))
                j--;            
            else if(isalpha(a[j]))
                i++;            
            else
                i++, j--;            
        }
        
        return a;
    }
};