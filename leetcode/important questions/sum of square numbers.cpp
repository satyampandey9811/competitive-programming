// link to question - https://leetcode.com/problems/sum-of-square-numbers/

class Solution {
public:
    bool judgeSquareSum(int c) {

        for(long long int i=0,j=sqrt(c);i<=j;){            
                if((i*i)+(j*j)==c)
                    return true;            
                else if((i*i)+(j*j)<c)
                    i++;
                else if((i*i)+(j*j)>c)
                    j--;            
        }
        return false;       
    }
};