// link to question - https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int n = a.size(), sum = 0, ans = 0;
        map<int, int> m;
        m[0] = 1;
        
        for(int i = 0; i < n; i++){
            sum += a[i];
            ans += m[sum - k];
            m[sum]++;
        }
        
        return ans;
    }
};