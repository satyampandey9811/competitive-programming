// link to question - https://leetcode.com/problems/longest-harmonious-subsequence/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> m;
        for(int& i: nums) m[i]++;
        
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(m.count(nums[i] - 1)) ans = max(ans, m[nums[i]] + m[nums[i] - 1]);
            if(m.count(nums[i] + 1)) ans = max(ans, m[nums[i]] + m[nums[i] + 1]);
        }
        
        return ans;
    }
};