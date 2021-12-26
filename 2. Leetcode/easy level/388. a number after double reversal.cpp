// link to question - https://leetcode.com/problems/a-number-after-a-double-reversal/

class Solution {
public:
    int reverse(int num) {
        int x = 0;
        while (num) {
            x = x * 10 + num % 10;
            num /= 10;
        }
        return x;
    }
    
    bool isSameAfterReversals(int num) {
        int num1 = reverse(num);
        int num2 = reverse(num1);
        return num2 == num;
    }
};