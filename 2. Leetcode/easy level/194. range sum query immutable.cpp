// link to question - https://leetcode.com/problems/range-sum-query-immutable/

class NumArray {
    vector<int> a;
public:
    NumArray(vector<int>& nums) {        
        a.push_back(0);
        for(int i: nums) a.push_back(a.back() + i);
    }
    
    int sumRange(int i, int j) {
        return a[j + 1] - a[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */