// link to question - https://leetcode.com/problems/teemo-attacking/

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        int ans = 0;
        for(int i = 0; i < n - 1; i++) {
            ans += min(duration, timeSeries[i+1] - timeSeries[i]);
        }
        
        if(n) ans += duration;
        return ans;
    }
};