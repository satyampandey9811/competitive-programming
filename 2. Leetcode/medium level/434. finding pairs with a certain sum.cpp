// link to question - https://leetcode.com/problems/finding-pairs-with-a-certain-sum/

class FindSumPairs {
public:
    map<int, int> mp;
    vector<int> a, b;
    int m, n;
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size(), n = nums2.size();
        a = nums1, b = nums2;
        
        for(int j = 0; j < n; j++) {
            mp[b[j]]++;
        }
    }
    
    void add(int index, int val) {
        mp[b[index]]--;
        b[index] += val;
        mp[b[index]]++;
    }
    
    int count(int tot) {
        int res = 0;
        
        for(int i = 0; i < m; i++) {
            if(mp.count(tot - a[i])) res += mp[tot - a[i]];
        }
        
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */