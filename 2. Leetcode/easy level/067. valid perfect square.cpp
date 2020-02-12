// link to question - https://leetcode.com/problems/valid-perfect-square/

class Solution {
public:
    bool isPerfectSquare(int num) {
        for(long long int i=0;i<=num;i++){
            if(i*i==num)
                return true;
            if(i*i>num)
                break;
        }
        return false;
    }
};