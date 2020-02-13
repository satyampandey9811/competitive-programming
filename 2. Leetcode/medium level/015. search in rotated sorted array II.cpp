// link to question - https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

class Solution {
public:
    int findPivot(vector<int> nums, int size){
        int ans = 0;
        int low = 0, high = size - 1, mid;
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
        return ans;
    }
    
    bool search(vector<int>& nums, int t) {
        int n = nums.size();
        int pivot = findPivot(nums, n);
        bool ans = binary_search(nums.begin(), nums.begin() + pivot, t);
        if(ans) return true;
        ans = binary_search(nums.begin() + pivot, nums.end(), t);
        return ans;
    }
};