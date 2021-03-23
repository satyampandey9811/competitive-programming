// link to question - https://leetcode.com/problems/3sum-with-multiplicity/

class Solution {
public:
    int threeSumMulti(vector<int>& a, int t) {
        int n = a.size(), mod = 1e9 + 7, ans = 0;
        vector<vector<int>> sum(201, vector<int>(n + 1));
        
        for(int i = 1; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                sum[a[i] + a[j]][i]++;
            }
        }
        
        for(int i = 0; i < 201; i++) {
            for(int j = n - 1; j > 0; j--) {
                sum[i][j] += sum[i][j+1];
            }
        }
        
        for(int i = 0; i < n - 2; i++) {
            for(int j = 0; j < 201; j++) {
                if(a[i] + j == t) {
                    ans = (ans + sum[j][i+1]) % mod;
                }
            }
        }
        
        return ans;
    }
};