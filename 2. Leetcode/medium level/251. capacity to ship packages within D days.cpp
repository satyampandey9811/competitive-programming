// link to question - https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
public:
    int shipWithinDays(vector<int>& a, int d) {
        int low = *max_element(a.begin(), a.end());
        int high = accumulate(a.begin(), a.end(), 0), mid;
        
        while(low < high) {
            mid = low + (high - low) / 2;
            int c = 1, sum = 0;
        
            for(int i = 0; i < (int)a.size(); i++) {
                sum += a[i];
                if(sum > mid) {
                    c++;
                    sum = a[i];
                }
            }
            
            if(c <= d) high = mid;
            else low = mid + 1;
        }
        
        return low;
    }
};