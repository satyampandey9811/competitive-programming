// link to question - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        int low = 0, high = n - 1, mid;
        while(low <= high){
            mid = low + (high - low) / 2;            
            if(nums[mid] >= nums[0])
                low = mid + 1;
            else {
                if(mid < 1) break;
                if(nums[mid] > nums[mid - 1])
                    high = mid - 1;
                else{
                    ans = mid;
                    break;
                }
            }
        }
        return nums[ans];
    }
};