// link to question - https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/

class Solution {
public:
    int minOperations(vector<int>& a, vector<int>& b) {
        int ans = 0;
        sort(a.begin(), a.end());
        int gcd = b[0];
        int m = a.size(), n = b.size();
        
        for (int i = 1; i < n; i++) {
            gcd = __gcd(gcd, b[i]);
        }
        
        for (int i = 0; i < m; i++) {
            if (gcd >= a[i]) {
                if (gcd % a[i] == 0) {
                    return i;
                }
            }
            else {
                return -1;
            }
        }
        
        return -1;
    }
};