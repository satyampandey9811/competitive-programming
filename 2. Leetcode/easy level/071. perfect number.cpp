// link to question - https://leetcode.com/problems/perfect-number/

class Solution {
public:
    bool checkPerfectNumber(int n) {
        if(n==33550336)
            return true;
        if(n<=1 or n>50000)
            return false;
        int sum=0;
        
        for(int i=1;i<=n/2;i++){
            if(n%i==0)
                sum+=i;
        }
        if(sum==n)
            return true;
        else
            return false;
    }
};