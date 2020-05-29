// link to question - https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution {
public:        
    int maxScore(vector<int>& a, int k) {
        int n = a.size(), sum = 0, ans = INT_MIN;
        vector<int> sumfront(n + 1);
        vector<int> sumbehind(n + 1);        
        
        for(int i = 0; i < n; i++) {
            sum += a[i];
            sumfront[i+1] = sum;
        } sum = 0;
        for(int i = n - 1; i >= 0; i--) {
            sum += a[i];
            sumbehind[i] = sum;
        }
        reverse(sumbehind.begin(), sumbehind.end());
        
        for(int i = 0; i <= k; i++) {
            ans = max(ans, sumfront[i] + sumbehind[k-i]);
        }
        
        return ans;
    }
};