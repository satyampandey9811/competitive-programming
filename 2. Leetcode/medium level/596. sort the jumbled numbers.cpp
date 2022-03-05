// link to question - https://leetcode.com/problems/sort-the-jumbled-numbers/

class Solution {
public:
    vector<int> sortJumbled(vector<int>& m, vector<int>& a) {
        int n = a.size();
        vector<array<int, 2>> b(n);
        for (int i = 0; i < n; i++) {
            b[i][1] = i;
            
            int val = 0;
            vector<int> c;
            int x = a[i];
            if (x == 0) c.push_back(m[0]);
            while (x) {
                c.push_back(m[x % 10]);
                x /= 10;
            }
            
            for (int j = c.size() - 1; j >= 0; j--) {
                val = val * 10 + c[j];
            }
            
            b[i][0] = val;
        }
        
        sort(b.begin(), b.end());
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = a[b[i][1]];
        }
        
        return ans;
    }
};