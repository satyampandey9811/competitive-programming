// link to question - https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/

class Solution {
public:
    bool checkPowersOfThree(int n) {
        for(int i = 0; i < (1 << 15); i++) {
            int sum = 0;
            for(int j = 0; j < 15; j++) {
                if(i & (1 << j)) {
                    sum += pow(3, j);
                }
            }
            
            if(sum == n) return 1;
        }
        return 0;
    }
};