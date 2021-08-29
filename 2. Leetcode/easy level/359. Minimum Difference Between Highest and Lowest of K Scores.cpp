// link to question - https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-score/

class Solution {
public:
    int minimumDifference(vector<int>& a, int k) {
        int n = a.size();
        sort(a.begin(), a.end());
        int ans = INT_MAX;
        
        for(int i = k - 1; i < n; i++) {
            ans = min(ans, a[i] - a[i-k+1]);
        }
        
        return ans;
    }
};