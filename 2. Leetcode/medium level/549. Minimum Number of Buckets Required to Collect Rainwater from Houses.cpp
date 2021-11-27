// link to question - https://leetcode.com/problems/minimum-number-of-buckets-required-to-collect-rainwater-from-houses/

class Solution {
public:
    int minimumBuckets(string a) {
        int n = a.size();
        
        if (n == 1 and a == "H") return -1;
        if (n == 1) return 0;
        if (n == 2 and a == "HH") return -1;
        if (a[0] == 'H' and a[1] == 'H') return -1;
        if (a[n-2] == 'H' and a[n-1] == 'H') return -1;
        
        for (int i = 0; i < n - 2; i++) {
            if (a[i] == 'H' and a[i+1] == 'H' and a[i+2] == 'H') return -1;
        }
        
        int ans = 0;
        vector<bool> p(n);
        
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == '.') continue;
            if (a[i+1] == 'H') {
                if (!p[i-1]) ans++;
                continue;
            }
            if (i - 1 >= 0) {
                if (!p[i-1]) {
                    ans++;
                    p[i+1] = true;
                }
            }
            else {
                ans++;
                p[i+1] = true;
            }
        }
        
        if (a[n-1] == 'H') {
            if (!p[n-2]) ans++;
        }
        
        return ans;
    }
};