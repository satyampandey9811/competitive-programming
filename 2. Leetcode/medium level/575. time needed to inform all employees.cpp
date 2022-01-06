// link to question - https://leetcode.com/problems/time-needed-to-inform-all-employees/

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans = 0;
        vector<vector<int>> a(n+1);
        manager[headID] = n;
        for (int i = 0; i < n; i++) {
            a[manager[i]].push_back(i);
        }
        vector<int> time(n);
        queue<int> q;
        q.push(headID);
        
        while (!q.empty()) {
            for (int i = q.size(); i > 0; i--) {
                auto person = q.front();
                q.pop();
                ans = max(ans, time[person]);
                
                for (auto &j :a[person]) {
                    time[j] = time[person] + informTime[person];
                    q.push(j);
                }
            }
        }
        
        return ans;
    }
};