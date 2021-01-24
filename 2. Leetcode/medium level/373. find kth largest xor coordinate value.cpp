// link to question - https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& a, int k) {
        int m = a.size(), n = a[0].size();
        vector<int> b = {a[0][0]};
        
        for(int i = 1; i < n; i++) {
            a[0][i] ^= a[0][i-1];
            b.emplace_back(a[0][i]);
        }
        
        for(int i = 1; i < m; i++) {
            a[i][0] ^= a[i-1][0];
            b.emplace_back(a[i][0]);
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                a[i][j] = a[i][j] ^ a[i-1][j] ^ a[i][j-1] ^ a[i-1][j-1];
                b.emplace_back(a[i][j]);
            }
        }
        
        sort(b.begin(), b.end(), greater<int>());
        return b[k - 1];
    }
};