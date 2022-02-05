// link to question - https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/

class Solution {
public:
    int minimumSum(int num) {
        vector<int> a;
        int res = 1e8;
        
        while (num) {
            a.push_back(num % 10);
            num /= 10;
        }
        
        sort(a.begin(), a.end());
        
        do {
            res = min(res, a[0] + a[1] * 100 + a[2] * 10 + a[3]);
            res = min(res, a[0] * 10 + a[1] + a[2] * 10 + a[3]);
            res = min(res, a[0] * 100 + a[1] * 10 + a[2] + a[3]);
        } while (next_permutation(a.begin(), a.end()));
        
        return res;
    }
};