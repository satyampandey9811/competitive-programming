// link to question - https://leetcode.com/problems/minimum-speed-to-arrive-on-time/

class Solution {
public:
    int minSpeedOnTime(vector<int>& a, double hour) {
        int n = a.size();
        int start = 1, end = 1e7, mid;
        int res = -1;
        
        while(start <= end) {
            mid = start + (end - start) / 2;
            double x = 0;
            int i;
            
            for(i = 0; i < n; i++) {
                x = ceil(x);
                x += (double)a[i] / mid;
                
                if(x * 100 > hour * 100) break;
            }
            
            if(i == n and x * 100 <= hour * 100) {
                res = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        
        return res;
    }
};