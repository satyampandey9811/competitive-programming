// link to question - https://leetcode.com/problems/k-concatenation-maximum-sum/

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& a, int k) {        
        
        // check the hint 4 for understanding this solution.
        
        int n = a.size(), mod = 1e9 + 7; 
        long long int ans = 0LL, totalsum, sum = 0LL;
        totalsum = accumulate(a.begin(), a.end(), 0LL);
        
        for(int i = 0; i < n; i++) {
            sum += a[i];
            ans = max(ans, sum);            
            if(sum < 0) sum = 0;
        }
        
        int prefixSum = a[0], suffixSum = a.back();
        int maxPrefixSum = max(0, a[0]), maxSuffixSum = max(0, a.back());
        
        for(int i = 1; i < n; i++) {
            prefixSum += a[i];
            maxPrefixSum = max(maxPrefixSum, prefixSum);
        }
        
        for(int i = n - 2; i >= 0; i--) {
            suffixSum += a[i];
            maxSuffixSum = max(maxSuffixSum, suffixSum);
        }
            
        ans = max(ans, totalsum * k);
        if(k > 1) 
            ans = max(ans, maxPrefixSum + maxSuffixSum + (k - 2) * max(0LL, totalsum));
        
        return ans % mod;
    }
};