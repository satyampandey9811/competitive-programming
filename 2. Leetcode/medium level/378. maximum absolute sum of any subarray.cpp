// link to question - https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/

class Solution {
public:
    int maxAbsoluteSum(vector<int>& a) {
        int finalAns, ans = 0, sum = 0, n = a.size();
        
        for(int i = 0; i < n; i++) {
            sum += a[i];
            ans = max(ans, sum);
            if(sum < 0) {
                sum = 0;
            }
        }
        
        finalAns = ans;
        sum = 0, ans = 0;
        
        for(int i = 0; i < n; i++) {
            a[i] *= -1;
        }
        
        for(int i = 0; i < n; i++) {
            sum += a[i];
            ans = max(ans, sum);
            if(sum < 0) {
                sum = 0;
            }
        }
        
        finalAns = max(finalAns, ans);
        return finalAns;
    }
};