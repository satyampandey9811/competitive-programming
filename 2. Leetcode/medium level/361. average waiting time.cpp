// link to question - https://leetcode.com/problems/average-waiting-time/

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& a) {
        int n = a.size();
        double sum = 0;
        int s, e = a[0][0];
        
        for(int i = 0; i < n; i++) {
            s = e;
            s = max(s, a[i][0]);
            e = s + a[i][1];
            sum += e - a[i][0];
        }
        
        sum /= n;
        return sum;
    }
};