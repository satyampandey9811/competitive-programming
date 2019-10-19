// link to question - https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) {
        if(x<0)
            return INT_MIN;        
        int a=0,b=INT_MAX/2;
        while(a<=b){
            int mid=(a+b)/2;
            if(1LL*mid*mid<=x and 1LL*(mid+1)*(mid+1)>x)
                return mid;
            else if(1LL*mid*mid<x)
                a=mid+1;
            else
                b=mid-1;
        }
        return 0;
    }
};