// link to question - https://leetcode.com/problems/binary-subarrays-with-sum/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& a, int t) {
        int n = a.size();
        int ans = 0, sum = 0;
        unordered_map<int, int> m;    
        m[0] = 1;
        
        for(int i = 0; i < n; i++) {
            sum += a[i];
            ans += m[sum - t];
            m[sum]++;
        }
        
        return ans;
    }
};