// link to question - https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/

class Solution {
public:
    int minSwaps(vector<int>& a) {
        int n = a.size(), ans = INT_MAX;
        vector<int> one(n + 1);
    
        for (int i = 1; i <= n; i++) {
            if (a[i-1] == 1) one[i]++;
            one[i] += one[i-1];
        }
        
        int tone = 0;
        for (int i = 0; i < n; i++) {
            if (a[i]) tone++;
        }
        
        for (int i = 0; i <= n - tone; i++) {
            ans = min(ans, tone - one[i + tone] + one[i]);
        }
        
        for (int i = 0; i < tone; i++) {
            int val = max(0, i - one[i]) + max(0, tone - i - one[n] + one[n - tone + i]);
            ans = min(ans, val);
        }
        
        return ans;
    }
};