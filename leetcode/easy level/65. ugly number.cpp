// link to question - https://leetcode.com/problems/ugly-number/

class Solution {
public:
    bool isUgly(int n) {
        
        if(n<1)
            return false;
        if(n==1)
            return 1;
        while(n>0){
            
            if(n%5==0)
                n/=5;
            else if(n%3==0)
                n/=3;
            else if(n%2==0)
                n/=2;
            else if(n==1)
                return true;
            else
                return false;
        }
        return false;
    }
};