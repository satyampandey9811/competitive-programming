// link to question - https://leetcode.com/problems/range-sum-query-mutable/

class NumArray {
public:
    vector<int> a;
    int n;
    
    void build(int i, int l, int r, vector<int>& nums) {
        if(l == r) {
            a[i] = nums[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * i, l, mid, nums);
        build(2 * i + 1, mid + 1, r, nums);
        a[i] = a[2 * i] + a[2 * i + 1];
    }
    
    void update(int i, int& ind, int& val, int l, int r) {
        if(l == r) {
            a[i] = val;
            return;
        }
        int mid = (l + r) / 2;
        if(ind <= mid) update(2 * i, ind, val, l, mid);
        else update(2 * i + 1, ind, val, mid + 1, r);
        a[i] = a[2 * i] + a[2 * i + 1];
    }
    
    int query(int i, int l, int r, int s, int e) {
        if(e < l or r < s) return 0;
        if(l >= s and r <= e) return a[i];
        int mid = (l + r) / 2;
        return query(2 * i, l, mid, s, e) + query(2 * i + 1, mid + 1, r, s, e);
    }
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        a.resize(n * 4);
        build(1, 0, n - 1, nums);
    }
    
    void update(int index, int val) {
        update(1, index, val, 0, n - 1);
    }
    
    int sumRange(int left, int right) {
        return query(1, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */