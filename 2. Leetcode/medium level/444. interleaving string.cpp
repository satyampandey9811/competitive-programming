// link to question - https://leetcode.com/problems/interleaving-string/

class Solution {
public:
    string a, b, c;
    int m, n, o;
    char dp[101][101];
    
    char go(int i, int j, int k) {
        if(k == o) return 'c';
        char &ans = dp[i][j];
        if(ans != 'a') return ans;

        ans = 'b';
        if(a[i] == c[k]) ans = go(i + 1, j, k + 1);
        if(ans == 'b' and b[j] == c[k]) ans = go(i, j + 1, k + 1);
        return ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        a = s1, b = s2, c = s3, m = a.size(), n = b.size(), o = c.size();
        if(m + n != o or m > o or n > o) return 0;
        memset(dp, 'a', sizeof dp);
        char d = go(0, 0, 0);
        return d == 'c';
    }
};