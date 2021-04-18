// link to question - https://leetcode.com/problems/single-threaded-cpu/

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& g) {
        int n = g.size();
        vector<int> ans;
        vector<vector<int>> a(n, vector<int>(3));
        for(int i = 0; i < n; i++) {
            a[i][0] = g[i][0];
            a[i][1] = g[i][1];
            a[i][2] = i;
        }
        sort(a.begin(), a.end());
        
        long long b = a[0][0], j = 0;
        set<pair<int, int>> s;
        
        for(int i = 0; i < n; i++) {
            while(j < n and a[j][0] <= b) {
                s.insert({a[j][1], a[j][2]});
                j++;
            }
            if(!s.size() and j < n) {
                s.insert({a[j][1], a[j][2]});
                j++;
            }
            int x = (*s.begin()).first, y = (*s.begin()).second;
            ans.push_back(y);
            if(g[y][0] > b) {
                b = g[y][0] + g[y][1];
            }
            else b += x;
            s.erase(s.begin());
        }
        
        return ans;
    }
};