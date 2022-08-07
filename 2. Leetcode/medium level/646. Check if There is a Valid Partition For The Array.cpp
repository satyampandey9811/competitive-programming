// link to question - https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/

class Solution {
public:
    int n;
    int dp[100002];
    
    bool go (int i, vector<int>& a) {
        int& ans = dp[i];
        if (ans != -1) return ans;

        int j = i;
        
        while (j < n and a[j] == a[i]) j++;
        
        if (j == n and j - i == 1) return ans = 0;
        if (j == n) return ans = 1;
        if (j - i > 2) {
            if (go (j, a)) return ans = 1;
            if (go (j - 1, a)) return ans = 1;
            return ans = 0;
        }
        if (j - i >= 2) return ans = go (j, a); 
        
        if (i + 2 < n and a[i + 1] == a[i] + 1 and a[i + 2] == a[i + 1] + 1) return ans = go (i + 3, a);
        return ans = 0;
    }
    
    bool validPartition(vector<int>& a) {
        n = a.size();
        memset(dp, -1, sizeof dp);
        return go(0, a);
    }
};