// link to question - https://leetcode.com/problems/water-bottles/

class Solution {
public:
    int numWaterBottles(int n, int e) {
        int ans = 0;
        while(n >= e) {                        
            ans += n - n % e;
            n = n/e + n % e;
        }
        ans += n;
        return ans;
    }
};