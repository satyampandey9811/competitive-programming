// link to question - https://leetcode.com/problems/course-schedule-iii/

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& a) {
        int n = a.size(), ans = 0;
        sort(a.begin(), a.end(), [](const vector<int>& x, const vector<int>& y) {
            return x[1] < y[1];
        });
        
        priority_queue<int> q;
        int i = 0, d = 0;
        
        for (int i = 0; i < n; i++) {
            q.push(a[i][0]);
            d += a[i][0];
            
            if (d > a[i][1]) {
                d -= q.top();
                q.pop();
            }
            else ans++;
        }
        
        return ans;
    }
};