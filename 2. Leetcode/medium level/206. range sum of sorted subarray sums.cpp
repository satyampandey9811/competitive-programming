// link to question - https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/

class Solution {
public:
    int rangeSum(vector<int>& a, int n, int l, int r) {
        int val = 1e9 + 7;
        vector<long long int> b;
        for(int i = 0; i < n; i++) {
            long long int sum = 0LL;
            for(int j = i; j < n; j++) {
                sum += a[j];
                b.push_back(sum);
            }
        }
        sort(b.begin(), b.end());
        int ans = 0;
        for(int i = l - 1; i < r; i++) {
            ans += b[i];
            ans %= val;
        }
        return ans;
    }
};