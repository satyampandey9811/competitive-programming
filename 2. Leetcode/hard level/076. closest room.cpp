// link to question - https://leetcode.com/problems/closest-room/

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& r, vector<vector<int>>& query) {
        int m = r.size(), n = query.size();
        vector<int> ans(n);
        vector<array<int, 3>> q(n);
        
        for(int i = 0; i < m; i++) swap(r[i][0], r[i][1]);
        sort(r.begin(), r.end());
        
        for(int i = 0; i < n; i++) {
            q[i][0] = query[i][1];
            q[i][1] = query[i][0];
            q[i][2] = i;
        }
        sort(q.rbegin(), q.rend());
        
        set<int> s;
        int j = m - 1, res;
        for(int i = 0; i < n; i++) {
            while(j >= 0 and r[j][0] >= q[i][0]) {
                s.insert(r[j--][1]);
            }
            if(!s.size()) {
                ans[q[i][2]] = -1;
                continue;
            }
            
            res = INT_MAX;
            auto it = s.lower_bound(q[i][1]);
            if(it != s.end()) {
                res = min(res, abs(*it - q[i][1]));
                ans[q[i][2]] = *it;
            }
            if(it != s.begin()) {
                it--;
                if(abs(*it - q[i][1]) <= res) {
                    ans[q[i][2]] = *it;
                }
            }
        }
        
        return ans;
    }
};