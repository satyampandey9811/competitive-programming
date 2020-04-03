// link to question - https://leetcode.com/problems/power-of-four/

class Solution {
public:
    bool isPowerOfFour(int num) {        
        long long n = num;
        if(n & (n - 1)) 
            return false;
                                
        if(n & 0x55555555)
            return true;
        return false;
    }
};