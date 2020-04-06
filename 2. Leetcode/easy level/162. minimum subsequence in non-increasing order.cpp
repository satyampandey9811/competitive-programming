// link to question - https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/

class Solution {
public:
    vector<int> minSubsequence(vector<int>& a) {
        vector<int> ans;
        int n = a.size(), res = 0;
        int sum = accumulate(a.begin(), a.end(), 0);
        sort(a.begin(), a.end(), greater<>());
        
        for(int i = 0; i < n; i++){
            res += a[i];
            ans.push_back(a[i]);
            sum -= a[i];
            if(res > sum)
                break;
        }        
        return ans;
    }
};