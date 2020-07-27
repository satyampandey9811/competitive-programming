// link to question - https://leetcode.com/problems/subarray-sums-divisible-by-k/

class Solution {
public:
    int subarraysDivByK(vector<int>& a, int k) {
        int n = a.size();
        map<int, int> m;
        m[0] = 1;
        int ans = 0, sum = 0;
        
        for(int i = 0; i < n; i++) {
            sum = (sum + a[i] % k + k) % k;
            ans += m[sum];
            m[sum]++;
        }
        
        return ans;
    }
};