// link to question - https://leetcode.com/problems/smallest-integer-divisible-by-k/

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        const int N = k;
        int num = 0, ans = 0;
        
        for (int i = 0; i < N; i++) {
            ans++;
            num = (num * 10 + 1) % k;
            if (num == 0) return ans;
        }
        
        return -1;
    }
};