// link to question - https://leetcode.com/problems/most-visited-sector-in-a-circular-track/

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& a) {
        vector<int> ans(n + 1), res;
        int m = a.size();
        
        for(int i = 0; i < m - 1; i++) {
            ans[a[i]]++;
            int x = a[i];
            int y = a[i+1];
            if(y < x) {
                for(int j = x + 1; j <= n; j++) ans[j]++;
                for(int j = 1; j < y; j++) ans[j]++;
            }
            else for(int j = x + 1; j < y; j++) ans[j]++;
        }
        
        ans[a.back()]++;
        
        int maxnum = *max_element(ans.begin(), ans.end());
        for(int i = 1; i <= n; i++) {
            if(ans[i] == maxnum) res.push_back(i);
        }
        
        return res;
    }
};