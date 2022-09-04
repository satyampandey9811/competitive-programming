// link to question - https://leetcode.com/problems/longest-nice-subarray/

class Solution {
public:
    int longestNiceSubarray(vector<int>& a) {
        int ans = 1, n = a.size();
        int val = a[0];
        int j = 0;
        
        for (int i = 1; i < n;) {
            if ((val & a[i]) == 0) {
                ans = max(ans, i - j + 1);
                val = val | a[i];
                i++;
            }
            else {
                val = val ^ a[j];
                j++;
            }
        }
        
        return ans;
    }
};