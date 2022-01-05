// link to question - https://leetcode.com/problems/sum-of-distances-in-tree/

class Solution {
public:
    vector<int> distance, count;
    vector<vector<int>> a;
    
    void dfs1 (int i, int p) {
        for (auto &j :a[i]) {
            if (j == p) continue;
            dfs1(j, i);
            distance[i] += distance[j] + count[j];
            count[i] += count[j];
        }
        count[i]++;
    }
    
    void dfs2 (int i, int p) {
        for (auto &j :a[i]) {
            if (j == p) continue;
            distance[j] += distance[i] + count[i] - distance[j] - 2 * count[j];
            count[j] = count[i];
            dfs2(j, i);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        distance = vector<int>(n);
        count = vector<int>(n);
        a = vector<vector<int>>(n);
        
        for (auto &i :edges) {
            a[i[0]].push_back(i[1]);
            a[i[1]].push_back(i[0]);
        }
        
        dfs1(0, -1);
        dfs2(0, -1);
        return distance;
    }
};