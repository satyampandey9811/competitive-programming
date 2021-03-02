// link to question - https://leetcode.com/problems/set-mismatch/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& a) {
        int n = a.size(), x, y = 0;
        
        for(int i = 0; i < n; i++) y ^= a[i];
        for(int i = 1; i <= n; i++) y ^= i;
        
        for(int i = 0; i < n; i++) {
            x = a[i] % (n + 1);
            a[x-1] += n + 1;
            if(a[x-1] / (n + 1) > 1) break;
        }
        
        return {x, x ^ y};
    }
}