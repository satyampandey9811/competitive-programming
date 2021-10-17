// link to question - https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/

class Solution {
public:
    int countMaxOrSubsets(vector<int>& a) {
        int n = a.size();
        int mx = 0;
        int ans = 0;
        
        for(int i = 0; i < (1 << n); i++) {
            int bo = 0;
            for(int j = 0; j < n; j++) {
                if(i & (1 << j)) {
                    bo |= a[j];
                }
            }
            if(bo == mx) ans++;
            if(bo > mx) {
                mx = bo;
                ans = 1;
            }
        }
        
        return ans;
    }
};