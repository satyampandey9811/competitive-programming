// link to question - https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    int minEatingSpeed(vector<int>& a, int h) {
        int n = a.size();
        int low = 1;
        int mid, high = *max_element(a.begin(), a.end());
        
        while(low < high) {
            mid = low + (high - low) / 2;
            int c = 0;
            for(int i = 0; i < n; i++) c += (a[i] + mid - 1) / mid;  
            if(c <= h) high = mid;
            else low = mid + 1;
        }
        
        return low;
    }
};