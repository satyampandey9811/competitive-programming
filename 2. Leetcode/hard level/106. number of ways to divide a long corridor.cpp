// link to question - https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/

class Solution {
public:
    int numberOfWays(string a) {
        int mod = 1e9 + 7;
        int n = a.size();
        
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 'S') c++;
        }
        if (c == 0) return 0;
        if (c & 1) return 0;
        
        bool f = false;
        int last = -1;
        vector<int> ans;
        c = 0;
        
        for (int i = 0; i < n; i++) {
            if (a[i] == 'S') c++;
            if (c == 2) {
                f = true;
                last = i;
                c = 0;
            }
            else if (c == 1) {
                if (f) {
                    ans.push_back(i - last);
                    f = false;
                }
            }
        }
        
        long long res = 1;
        int l = ans.size();
        
        for (int i = 0; i < l; i++) {
            res = (res * ans[i]) % mod;
        }
        
        return res;
    }
};