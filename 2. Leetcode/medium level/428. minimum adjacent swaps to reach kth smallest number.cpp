// link to question - https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/

class Solution {
public:
    void go(string& nums) {
        int n = nums.size(), k, l;
    	for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
    	if (k < 0) {
    	    reverse(nums.begin(), nums.end());
    	} else {
    	    for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            } 
    	    swap(nums[k], nums[l]);
    	    reverse(nums.begin() + k + 1, nums.end());
        }
    }
    
    int getMinSwaps(string nums, int t) {
        string s = nums;
        for(int i = 0; i < t; i++) {
            go(s);
        }
        
        int n = s.size(), ans = 0;
        int i = 0;
        while(i < n and s[i] == nums[i]) i++;
        if(i == n) return 0;
        int c = i;
        
        while(i < n) {
            for(int j = c; j < n; j++) {
                if(nums[j] == s[i]) {
                    nums[j] = 'A';
                    break;
                }
                if(nums[j] >= '0' and nums[j] <= '9') ans++;
            }
            i++;
        }
        
        return ans;
    }
};