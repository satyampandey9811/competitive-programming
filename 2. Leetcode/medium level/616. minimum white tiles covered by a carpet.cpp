// link to question - https://leetcode.com/problems/maximum-white-tiles-covered-by-a-carpet/

class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& a, int len) {
        int n = a.size();
        vector<int> b(n + 1);
        sort(a.begin(), a.end());
        
        for (int i = 1; i <= n; i++) {
            b[i] = a[i - 1][1] - a[i - 1][0] + 1;
            b[i] += b[i - 1];
        }
        
        map<pair<int, int>, int> m;
        for (int i = 0; i < n; i++) {
            m[{a[i][0], a[i][1]}] = i;
        }
        
        int ans = 0, sum;
        int start, si;
        int end, ei;
        
        for (auto &i :m) {
            start = i.first.first;
            si = i.second;
            
            auto it = m.lower_bound({start + len - 1, 0});
            if (it == m.end()) {
                it--;
                ei = it -> second;
                sum = b[ei + 1] - b[si];
                sum -= max(0, it -> first.second - (start + len - 1));
            }
            else {
                if (it -> first.first == start + len - 1) sum = 1;
                else sum = 0;
                if (it == m.begin()) goto z;
                it--;
                ei = it -> second;
                sum += max(0, b[ei + 1] - b[si]);
                sum -= max(0, it -> first.second - (start + len - 1));
            }
            
            z:
            ans = max(ans, sum);
        }
        
        // for (auto &i: m) {
        //     cout << i.first.first << ' ' << i.first.second << endl;
        // }
        
        return ans;
    }
};