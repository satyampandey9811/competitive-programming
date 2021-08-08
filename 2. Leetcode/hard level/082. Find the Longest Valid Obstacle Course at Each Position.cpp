// link to question - https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& a) {
        int n = a.size();
        vector<int> ans;
        vector<int> low(n + 2, INT_MAX);
        low[0] = INT_MIN;
        
        for(int i = 0; i < n; i++) {
            int it = upper_bound(low.begin(), low.end(), a[i]) - low.begin();
            ans.push_back(it);
            low[it] = a[i];
        }
        
        return ans;
    }
};