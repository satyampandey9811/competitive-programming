// link to question - https://leetcode.com/problems/power-of-three/

class Solution {
public:
    bool isPowerOfThree(int n) {
        
        for(int i=0;i<=log(n)/log(3)+1;i++){
            if(pow(3,i)==n)
                return true;
        }
        return false;
    }
};