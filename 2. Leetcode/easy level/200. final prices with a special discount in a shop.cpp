// link to question - https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/

class Solution {
public:
    vector<int> finalPrices(vector<int>& a) {        
        int n = a.size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {            
            ans[i] = a[i];
            for(int j = i + 1; j < n; j++) {
                if(a[j] <= a[i]) {
                    ans[i] = a[i] - a[j];                    
                    break;
                }
            }            
        }
        return ans;
    }
};