// link to question - https://leetcode.com/problems/two-best-non-overlapping-events/

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& a) {
        int n = a.size();
        sort(a.begin(), a.end(), [](vector<int>& x, vector<int>& y) {
            return x[1] < y[1];
        });
        
        int ans = a[0][2], last = a[0][2];
        set<pair<int, int>> s;
        s.insert({a[0][1], a[0][2]});
        
        for(int i = 1; i < n; i++) {
            auto it = s.lower_bound({a[i][0], 0});
            if(it == s.begin()) {
                ans = max(ans, a[i][2]);
            }
            else {
                it--;
                ans = max(ans, a[i][2] + (*it).second);
            }
            s.insert({a[i][1], max(a[i][2], last)});
            last = max(last, a[i][2]);
        }
        
        return ans;
    }
};