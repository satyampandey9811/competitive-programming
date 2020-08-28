// link to question - https://leetcode.com/problems/split-array-largest-sum/

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long int low = *max_element(nums.begin(), nums.end());
        long long int high = accumulate(nums.begin(), nums.end(), 0LL), mid;
        
        while(low < high) {
            mid = low + (high - low) / 2;
            long long int c = 1, sum = 0LL;
            for(int i = 0; i < (int)nums.size(); i++) {
                sum += nums[i];
                if(sum > mid) {
                    c++;
                    sum = nums[i];
                }
            }
            
            if(c > m) low = mid + 1;
            else high = mid;
        }
        
        return low;
    }
};