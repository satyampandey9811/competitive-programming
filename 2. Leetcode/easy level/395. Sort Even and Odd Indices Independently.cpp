// link to question - https://leetcode.com/problems/sort-even-and-odd-indices-independently/

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& a) {
        int n = a.size();
        vector<int> b, c;
        for (int i = 0; i < n; i += 2) {
            b.push_back(a[i]);
        }
        for (int i = 1; i < n; i += 2) {
            c.push_back(a[i]);
        }
        sort(b.begin(), b.end());
        sort(c.rbegin(), c.rend());
        
        vector<int> ans(n);
        int j = 0;
        for (int i = 0; i < b.size(); i++) {
            ans[j] = b[i];
            j += 2;
        }
        j = 1;
        for (int i = 0; i < c.size(); i++) {
            ans[j] = c[i];
            j += 2;
        }
        
        return ans;
    }
};