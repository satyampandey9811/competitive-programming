// link to question - https://leetcode.com/problems/sum-of-all-subset-xor-totals/

class Solution {
public:
    int subsetXORSum(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        
        for(int i = 0; i < (1 << n); i++) {
            int sum = 0;
            for(int j = 0; j < n; j++) {
                if(i & (1 << j)) {
                    sum ^= a[j];
                }
            }
            ans += sum;
        }
        
        return ans;
    }
};