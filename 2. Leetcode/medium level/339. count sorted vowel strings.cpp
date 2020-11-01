// link to question - https://leetcode.com/problems/count-sorted-vowel-strings/

class Solution {
public:
    int countVowelStrings(int n) {
        int ans = 0;
        vector<vector<int>> a(n, vector<int>(5));
        
        for(int i = 0; i < 5; i++) a[0][i] = 1;
        for(int i = 1; i < n; i++) a[i][0] = 1;
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < 5; j++) {
                a[i][j] = a[i][j-1] + a[i-1][j];
            }
        }
        
        for(int i = 0; i < 5; i++) ans += a[n-1][i];
        return ans;
    }
};