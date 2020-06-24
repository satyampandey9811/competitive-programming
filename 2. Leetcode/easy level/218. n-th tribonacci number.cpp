// link to question - https://leetcode.com/problems/n-th-tribonacci-number/

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        int a = 0, b = 1, c = 1, x;
        for(int i = 3; i <= n; i++){
            x = a + b + c;
            a = b;
            b = c;
            c = x;
        }
        return c;
    }
};