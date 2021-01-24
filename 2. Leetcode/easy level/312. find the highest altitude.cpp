// link to question - https://leetcode.com/problems/find-the-highest-altitude/

class Solution {
public:
    int largestAltitude(vector<int>& a) {
        int ans = 0, sum = 0;
        for(int i = 0; i < a.size(); i++) {
            sum += a[i];
            ans = max(ans, sum);
        }
        
        return ans;
    }
};