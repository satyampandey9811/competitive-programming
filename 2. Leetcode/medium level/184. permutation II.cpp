// link to question - https://leetcode.com/problems/permutations-ii/

class Solution {
public:
    vector<vector<int>> ans;
    
    void nextPermutation(vector<int>& nums, int& n) {
        int k, l;
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
        ans.push_back(nums);
    }    
    
    int fact(int n) {
        int ans = 1;
        for(int i = n; i > 1; i--) ans *= i;
        return ans;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ans.push_back(nums);
        int n = nums.size();
        int loop = fact(n);
        
        unordered_map<int, int> m;
        for(int i: nums) m[i]++;
        for(auto i: m) loop /= fact(i.second);
        
        for(int i = 1; i < loop; i++) {
            nextPermutation(nums, n);
        }
        return ans;   
    }
};