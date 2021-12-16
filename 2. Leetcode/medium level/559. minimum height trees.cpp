// link to question - https://leetcode.com/problems/minimum-height-trees/

class Solution {
public:
    vector<int> ans;
    map<pair<int, int>, int> m;
    
    int go(int i, int p, vector<vector<int>>& edges) {
        if (m.count({i, p})) return m[{i, p}];
        int res = 0;
        for (auto &j :edges[i]) {
            if (j == p) continue;
            res = max(res, go(j, i, edges));
        }
        return m[{i, p}] = res + 1;
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& a){
        vector<vector<int>> edges(n);
        for (int i = 0; i < n - 1; i++) {
            edges[a[i][0]].push_back(a[i][1]);
            edges[a[i][1]].push_back(a[i][0]); 
        }
        
        vector<int> mht(n);
        int minmht = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            mht[i] = go(i, -1, edges);
            minmht = min(minmht, mht[i]);
        }
        
        for (int i = 0; i < n; i++) {
            if (mht[i] == minmht) ans.push_back(i);
        }
        
        return ans;
    }
};