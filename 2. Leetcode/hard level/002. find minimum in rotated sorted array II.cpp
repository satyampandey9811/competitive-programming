// link to question - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

class Solution {
public:
    int findMin(vector<int>& nums) {        
        int n = nums.size(), ans = 0;
        int low = 0, high = n - 1, mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            ans = mid;
            if(nums[mid] == nums[low] and nums[mid] == nums[high]) 
                low++, high--;            
            else if(nums[mid] > nums[high])
                low = mid + 1;            
            else
                high = mid;            
        }
        return nums[ans];
    }
};