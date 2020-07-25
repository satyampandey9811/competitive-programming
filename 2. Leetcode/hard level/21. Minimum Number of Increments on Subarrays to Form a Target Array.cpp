// link to question - https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/

class Solution {
public:
    int minNumberOperations(vector<int>& a) {
        int n = a.size();
        int ans = a[0], m = a[0];
        for(int i = 1; i < n; i++) {
            if(a[i] >= m) 
                ans += a[i] - m;                            
            m = a[i];
        }
        return ans;
    }
};