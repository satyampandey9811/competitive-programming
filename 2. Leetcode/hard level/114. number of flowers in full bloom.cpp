// link to question - https://leetcode.com/problems/number-of-flowers-in-full-bloom/

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& a, vector<int>& p) {
        int n = a.size();
        map<int, int> m;
        
        for (int i = 0; i < n; i++) {
            m[a[i][0] * 2]++;
            m[a[i][1] * 2 + 1]++;
        }
        
        vector<vector<int>> q;
        int len = p.size();
        for (int i = 0; i < len; i++) {
            q.push_back({p[i], i});
        }
        
        sort(q.begin(), q.end());
        
        int i = 0;
        int c = 0;
        
        vector<vector<int>> b;
        
        for (auto &i : m) {
            b.push_back({i.first, i.second});
        }
        
        while (i < len and q[i][0] < b[0][0] / 2) i++;
        
        int sz = b.size();
        vector<int> ans(len);
        
        for (int j = 0; j < sz - 1; j++) {
            if (b[j][0] % 2 == 0) c += b[j][1];
            else c -= b[j][1];
            
            while (i < len and q[i][0] * 2 < b[j + 1][0]) {
                ans[q[i][1]] = c;
                i++;
            }
        }
        
        while (i < len and q[i][0] == b[sz - 1][0] / 1) {
            ans[q[i][1]] = c;
            i++;
        }
        
        return ans;
    }
};