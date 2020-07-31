// link to question - https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/

class Solution {
public:
    int countOrders(int n) {
        vector<int> a(n + 1);
        long long int ans = 1LL;
        for(int i = 1; i <= n; i++) {
            a[i] = i * 2 - 1;
            a[i] *= i;
            ans *= a[i];
            ans %= 1000000007;
        }        
        return ans;
    }
};