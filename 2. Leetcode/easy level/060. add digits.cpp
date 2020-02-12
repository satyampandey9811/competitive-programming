// link to question - https://leetcode.com/problems/add-digits/

class Solution {
public:
    int addDigits(int n) {
        if(!n)
            return 0;
        return (n%9==0)?9:n%9;            
    }
};