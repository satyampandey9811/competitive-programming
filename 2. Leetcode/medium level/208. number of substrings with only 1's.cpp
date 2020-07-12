// link to question - https://leetcode.com/problems/number-of-substrings-with-only-1s/

class Solution {
public:
    int numSub(string s) {
        int ans = 0, n = s.size(), val = 1e9 + 7;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') a[i] = 0;
            else a[i] = 1;
        }
        for(int i = 1; i < n; i++) {
            if(a[i] == 1) a[i] += a[i-1];
        }
        for(int i = 0; i < n; i++) {
            ans += a[i];
            ans %= val;
        }
        return ans;
    }
};