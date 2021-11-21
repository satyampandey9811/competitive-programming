// link to question - https://leetcode.com/problems/range-frequency-queries/

class RangeFreqQuery {
public:
    vector<vector<int>> a;
    
    RangeFreqQuery(vector<int>& arr) {
        a.resize(10001);
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            a[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        int n = a[value].size();
        if(n < 1) return 0;
        
        auto l = lower_bound(a[value].begin(), a[value].end(), left);
        auto r = upper_bound(a[value].begin(), a[value].end(), right);
        
        return r - l;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */