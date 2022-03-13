// link to question - https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves/

class Solution {
public:
    int maximumTop(vector<int>& a, int k) {
        int n = a.size();
        if (n == 1 and (k & 1)) return -1;
        int ans = 0;
        if (k < n) ans = a[k];
        for (int i = 0; i < min(n, k - 1); i++) ans = max(ans, a[i]);
        return ans;
    }
};