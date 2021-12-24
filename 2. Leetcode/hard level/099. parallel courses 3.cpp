// link to question - https://leetcode.com/problems/parallel-courses-iii/

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        int ans = 0, totaltime;
        vector<vector<int>> edges(n);
        vector<int> degree(n), duration(n);
        
        for (auto &i :relations) {
            edges[i[0] - 1].push_back(i[1] - 1);
            degree[i[1] - 1]++;
        }
        
        queue<int> q;
        
        for (int i = 0; i < n; i++) {
            if (degree[i] == 0) q.push(i);
        }
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            totaltime = duration[node] + time[node];
            ans = max(ans, totaltime);
            
            for (auto &j :edges[node]) {
                duration[j] = max(duration[j], totaltime);
                if (--degree[j] == 0) q.push(j);
            }
        }
        
        return ans;
    }
};