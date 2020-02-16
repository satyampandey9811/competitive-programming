// link to question - https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

class Solution {
public:
    int numberOfSteps (int n) {
        int ans = 0;
        while(n > 0){
            if(n & 1) n--;
            else n /= 2;
            ans++;
        }
        return ans;
    }
};