// link to question - https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        long long int p=0,a=1LL*x;
        while(a>0){
            p=(p*10)+a%10;
            a/=10;
        }
        if(p==x)
            return true;
        else
            return false;
    }
};