// link to question - https://leetcode.com/problems/count-primes/

class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)
            return 0;        
        int c=0,x,flag;
        for(int i=3;i<n;i+=2){
            
            x=i,flag=1;
            for(int j=2;j<=sqrt(x);){
                if(x%j==0){
                    flag=0;break;
                }
                if(j==2)
                    j=3;
                else
                    j+=2;
            }
            if(flag)
                c++;
        }
        return c+1;
    }
};