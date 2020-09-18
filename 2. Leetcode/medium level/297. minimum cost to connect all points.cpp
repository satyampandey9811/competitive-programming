// link to question - https://leetcode.com/problems/min-cost-to-connect-all-points/

class Solution {
public:
    int find(vector<int> &ds, int i) {
        return ds[i] == i ? i : ds[i] = find(ds, ds[i]); 
    }
    
    int minCostConnectPoints(vector<vector<int>>& a) {
        int n = a.size(), ans = 0, dist, count = 0;
        vector<int> parent(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        vector<array<int, 3>> graph;
         
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                dist = abs(a[i][0] - a[j][0]) + abs(a[i][1] - a[j][1]);
                graph.push_back({dist, i, j});
            }
        }
        
        make_heap(graph.begin(), graph.end(), greater<array<int, 3>>());
        
        while(graph.size()) {
            pop_heap(begin(graph), end(graph), greater<array<int, 3>>());
            auto [dist, i, j] = graph.back();
            graph.pop_back();
            
            i = find(parent, i), j = find(parent, j);
            if (i != j) {
                ans += dist;
                parent[i] = parent[j];
                // parent[j] = i;
                // if (parent[i] == -n)
                    // break;
                count++;
            }
            if(count == n - 1) break;
        }
        return ans;
    }
};