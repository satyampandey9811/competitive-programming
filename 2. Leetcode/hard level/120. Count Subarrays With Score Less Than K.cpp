// link to question - https://leetcode.com/problems/count-subarrays-with-score-less-than-k/

class Solution {
public:
    long long countSubarrays(vector<int>& a, long long k) {
        int i = 0, c = 0, j = 0;
        long long sum = 0, ans = 0;
        int n = a.size();
        
        while (i < n) {
            if ((sum + a[i]) * 1LL * (i - j + 1) < k) {
                sum += a[i];
                i++;
                c++;
                ans += c;
            }
            else {
                sum -= a[j];
                j++;
                c--;
            }
        }
        
        return ans;
    }
};