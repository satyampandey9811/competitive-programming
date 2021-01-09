// link to question - https://leetcode.com/problems/calculate-money-in-leetcode-bank/

class Solution {
public:
    int totalMoney(int n) {
        int c = 7, ans = 0;
        for(int i = 1; i <= n; i++) {
            if(i % 7 == 1) c -= 6;
            ans += c;
            c++;
        }
        
        return ans;
    }
};