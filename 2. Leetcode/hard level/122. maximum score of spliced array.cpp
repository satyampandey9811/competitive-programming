// link to question - https://leetcode.com/problems/maximum-score-of-spliced-array/

class Solution {
public:
    int go (vector<int>& a, vector<int>& b) {
        int ans = 0, sum = 0, n = a.size();
        for (int i = 0; i < n; i++) {
            sum += b[i] - a[i];
            if (sum < 0) sum = 0;
            ans = max(ans, sum);
        }
        return ans;
    }
    
    int maximumsSplicedArray(vector<int>& a, vector<int>& b) {
        int sum1 = accumulate(a.begin(), a.end(), 0);
        int sum2 = accumulate(b.begin(), b.end(), 0);
        int x = go(a, b);
        int y = go(b, a);
        return max(x + sum1, y + sum2);
    }
};