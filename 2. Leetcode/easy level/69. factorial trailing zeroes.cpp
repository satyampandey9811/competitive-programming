// link to question - https://leetcode.com/problems/factorial-trailing-zeroes/

class Solution {
public:
    
    int trailingZeroes(int n) {
        int c=0;
        for(long long int i=5;n/i>=1;i*=5){
            c+=n/i;
        }
        return c;
    }
};