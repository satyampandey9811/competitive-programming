// link to question - https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/

class Solution {
public:
    int findBestValue(vector<int>& a, int t) {
        int n = a.size(), sum;
        int low = 0, mid, high = *max_element(a.begin(), a.end());
        int diff = INT_MAX, ans = INT_MAX;
        
        while(low <= high) {
            mid = low + (high - low) / 2;
            sum = 0;
            
            for(int i = 0; i < n; i++) {
                if(a[i] > mid) sum += mid;
                else sum += a[i];
            }            
            
            if(sum >= t) high = mid - 1;
            else low = mid + 1;            
            
            if(abs(sum - t) == diff) ans = min(ans, mid);
            else if(abs(sum - t) < diff) diff = abs(sum - t), ans = mid; 
        }
        
        return ans;
    }
};