// link to : https://leetcode.com/problems/minimum-time-to-type-word-using-special-typer/

class Solution {
public:
    int minTimeToType(string a) {
        int ans = 0, n = a.size();
        int c = 0;
        
        for(int i = 0; i < n; i++) {
            int t = a[i] - 'a';
            if(c <= t) {
                ans += min(t - c, c + 1 + 25 - t);
                c = t;
            }
            else {
                ans += min(c - t, t + 1 + 25 - c);
                c = t;
            }
        }
        
        ans += n;
        return ans;
    }
};