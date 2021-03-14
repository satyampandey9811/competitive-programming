// link to question - https://leetcode.com/problems/find-center-of-star-graph/

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> a(n + 2);
        for(int i = 0; i < n; i++) {
            int x = edges[i][0], y = edges[i][1];
            a[x]++, a[y]++;
        }
        for(int i = 1; i < n + 2; i++) {
            if(a[i] == n) return i;
        }
        return 0;
    }
};