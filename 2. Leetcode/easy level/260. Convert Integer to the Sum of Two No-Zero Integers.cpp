// link to question - https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/

class Solution {
public:
    bool check(int i) {
        while(i > 0) {
            if(i % 10 == 0) return 0;
            i /= 10;
        }
        return 1;
    }
    
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i < n; i++) {
            if(check(i) and check(n - i)) return {i, n - i};
        }
        return {0, 0};
    }
};