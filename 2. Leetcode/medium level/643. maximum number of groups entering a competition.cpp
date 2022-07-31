// link to question - https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition/

class Solution {
public:
    int maximumGroups(vector<int>& a) {
        sort(a.begin(), a.end());
        int ct = 0, sum = 0;
        int prevCt = 1, prevSum = a[0];
        int ans = 1;
        int n = a.size();
        
        for (int i = 1; i < n; i++) {
            ct++;
            sum += a[i];
            
            if (sum > prevSum and ct > prevCt) {
                prevSum = sum;
                sum = 0;
                prevCt = ct;
                ct = 0;
                ans++;
            }
        }
        
        return ans;
    }
};