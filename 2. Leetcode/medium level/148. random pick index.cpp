// link to question - https://leetcode.com/problems/random-pick-index/

class Solution {
public:
    unordered_map<int, pair<int, vector<int>>> m;
    
    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]].second.push_back(i);
            m[nums[i]].first = 0;
        }
    }
    
    int pick(int target) {
        m[target].first++;
        m[target].first %= m[target].second.size();
        return m[target].second[m[target].first];        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */