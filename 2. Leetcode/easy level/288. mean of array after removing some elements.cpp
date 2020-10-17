// link to question - https://leetcode.com/problems/mean-of-array-after-removing-some-elements/

class Solution {
public:
    double trimMean(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        int x = n / 20, y = n / 20;
        int c = 0;
        int ans = 0.0;
        for(int i = 0; i < n; i++) {
            ans += a[i];
        }
        int p = 0, q = 0;
        for(int i = 0; i < n and c < x; i++, c++) {
            p += a[i];
        }
        c = 0;
        for(int i = n - 1; i >= 0 and c < y; i--, c++) {
            q += a[i];
        }
        ans = ans - p - q;
        return (double)ans / (n - x - y);
    }
};