// link to question - https://leetcode.com/problems/minimum-garden-perimeter-to-collect-enough-apples/

class Solution {
public:
    bool isThree(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(n % i == 0) ans++;
        }
        return ans == 3;
    }
};