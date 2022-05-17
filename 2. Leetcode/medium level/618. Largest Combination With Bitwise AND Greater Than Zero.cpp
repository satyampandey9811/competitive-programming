// link to question - https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/

class Solution {
public:
    int largestCombination(vector<int>& a) {
        int n = a.size();
        vector<int> b(30);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 30; j++) {
                if (1 & (a[i] >> j)) b[j]++;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < 30; i++) ans = max(ans, b[i]);
        return ans;
    }
};