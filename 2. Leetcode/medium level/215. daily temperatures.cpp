// link to question - https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n);        
        stack<pair<int, int>> s;  
        
        for(int i = 0; i < n; i++) {
            while(s.size() and a[i] > s.top().first) {
                ans[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.push({a[i], i});
        }
        
        return ans;
    }
};