// link to question - https://leetcode.com/problems/closest-divisors/

class Solution {
public:
    vector<int> closestDivisors(int n) {
        int x = n + 1, y = n + 2;
        int ans = INT_MAX;
        int p, q;
        for(int i = 1; i * i <= x; i++){
            if(x % i == 0){
                if(abs(i - x/i) < ans){
                    ans = abs(i - x/i);
                    p = i, q = x/i;
                }
            }
        }
        for(int i = 1; i * i <= y; i++){
            if(y % i == 0){
                if(abs(i - y/i) < ans){
                    ans = abs(i - y/i);
                    p = i, q = y/i;
                }
            }
        }
        return {p, q};
    }
};