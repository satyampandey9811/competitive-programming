// link to question - https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/

class Solution {
public:
    vector<int> minOperations(string a) {
        int n = a.size();
        vector<int> ans(n);
        
        for(int i = 0; i < n; i++) {
            if(a[i] == '1') {
                for(int j = 0; j < n; j++) {
                    if(i < j) {
                        ans[j] += j - i;
                    }
                    else {
                        ans[j] += i - j;
                    }
                }
            }
        }
        
        return ans;
    }
};