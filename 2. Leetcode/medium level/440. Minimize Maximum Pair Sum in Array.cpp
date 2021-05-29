// link to question - https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/

class Solution {
public:
    int minPairSum(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        int ans = 0;
        for(int i = 0; i < n/2; i++) {
            ans = max(ans, a[i] + a[n-i-1]);
        }
        return ans;
    }
};