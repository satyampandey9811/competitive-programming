// link to question - https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& a) {
        int sumr = accumulate(a.begin(), a.end(), 0), suml = 0;
        int n = a.size();
        vector<int> ans(n);
        
        for(int i = 0; i < n; i++) {
            sumr -= a[i];
            ans[i] = i * a[i] - suml;
            ans[i] += sumr - (n - 1 - i) * a[i];
            suml += a[i];
        }
        
        return ans;
    }
};