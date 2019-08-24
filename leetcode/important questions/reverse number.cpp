// link to question - https://leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {        
        long long num=x, val=0;
        
        while(num){
            val=(val*10)+(num%10);
            num/=10;
        }
        if(val>INT_MAX or val<INT_MIN) return 0;
        return val;
    }
};