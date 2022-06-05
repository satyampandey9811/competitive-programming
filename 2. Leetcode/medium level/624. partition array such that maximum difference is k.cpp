// link to question - https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/

class Solution {
public:
    int partitionArray(vector<int>& a, int k) {
        int n = a.size(), res = 0;
        sort(a.begin(), a.end());
        int mx = a[0];
        
        for (int i = 0; i < n; i++) {
            if (k < a[i] - mx) {
                mx = a[i];
                res++;
            }
        }
        
        res++;
        return res;
    }
};