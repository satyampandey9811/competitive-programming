// link to question - https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = n;
        vector<vector<bool>> a(n, vector<bool>(n, true));
        
        for(int i = 2; i <= n; i++) {
            for(int j = 0; j <= n - i; j++) {
                if(i == 2) {
                    if(s[j] == s[j+1]) a[j][j+i-1] = true, ans++;
                    else a[j][j+i-1] = false;
                }
                else {
                    if(s[j] == s[j+i-1] and a[j+1][j+i-2]) a[j][j+i-1] = true, ans++;
                    else a[j][j+i-1] = false;
                }
            }
        }
        
        return ans;
    }
};