// link to question - https://leetcode.com/problems/minimum-garden-perimeter-to-collect-enough-apples/

class Solution {
public:
    long long minimumPerimeter(long long na) {
        int low = 1, mid, high = 1e6;
        long long ans = 0, val;
        
        while(low <= high) {
            mid = low + (high - low) / 2;
            
            val = (2 * mid + 1) * 1LL * mid * (8 + (mid - 1) * 1LL * 4) / 2;
            
            if(val >= na) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        
        return ans * 8;
    }
};