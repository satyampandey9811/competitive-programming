// link to question - https://leetcode.com/problems/maximum-total-importance-of-roads/

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& r) {
        vector<int> a(n);
        
        int l = r.size();
        for (int i = 0; i < l; i++) {
            a[r[i][1]]++;
            a[r[i][0]]++;
        }
        
        long long res = 0;
        int m = n;
        sort(a.rbegin(), a.rend());
        
        for (int i = 0; i < m; i++) {
            res += a[i] * 1LL * n;
            n--;
        }
        
        return res;
    }
};