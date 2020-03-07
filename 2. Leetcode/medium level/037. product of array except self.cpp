// link to question - https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int n = a.size(), left = 1, right = 1;
        vector<int> ans(n, 1);
        for(int i = 0; i < n; i++){
            ans[i] *= left;
            ans[n - i - 1] *= right;
            left *= a[i];
            right *= a[n - i - 1];            
        }
        return ans;
    }
};