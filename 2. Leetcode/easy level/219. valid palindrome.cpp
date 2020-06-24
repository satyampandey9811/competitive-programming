// link to question - https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()==0)
            return true;           
        string a;
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i]))
                a+=tolower(s[i]);
        }
        for(int i=0,j=a.size()-1;i<a.size()/2;i++,j--){
            if(a[i]!=a[j])
                return false;
        }
        return true;
    }
};