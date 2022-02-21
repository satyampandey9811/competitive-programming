// link to question - https://leetcode.com/problems/count-integers-with-even-digit-sum/

class Solution {
public:
    int countEven (int num) {
        int res = 0;
        int sum;
        
        for (int i = 1; i <= num; i++) {
            int y = i;
            sum = 0;
            
            while (y) {
                sum += y % 10;
                y /= 10;
            }
            
            if (sum % 2 == 0) {
                res++;
            }
        }
        
        return res;
    }
};