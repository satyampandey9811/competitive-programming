// link to question - https://leetcode.com/problems/shuffle-an-array/

class Solution {
public:
    vector<int> a, b;
    
    Solution(vector<int>& nums) {
        a = nums;
        b = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return a;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        next_permutation(b.begin(), b.end());
        return b;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */