// link to question - https://leetcode.com/problems/sign-of-the-product-of-an-array/

class Solution {
public:
    int arraySign(vector<int>& a) {
        int n = a.size(), prod = 1;
        for(int i = 0; i < n; i++) {
            if(a[i] == 0) {
                prod = 0;
                break;
            }
            if(a[i] < 0) prod *= -1;
        }
        if(prod > 0) return 1;
        if(prod < 0) return -1;
        return 0;
    }
};