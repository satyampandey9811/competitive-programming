// link to question - https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        vector<int> ans(n);
        
        int i = 0;
        
        for(int j = 0; j < n; j++) {
            if(i >= n) i = 1;
            ans[i] = a[j];
            i += 2;
        }
        
        return ans;
    }
};