// link to question - https://leetcode.com/problems/meeting-rooms-iii/

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        int len = a.size();
        
        vector<int> times(n);
        int val = 0, ans, time;
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> end;
        priority_queue<int, vector<int>, greater<int>> free;
        for (int i = 0; i < n; i++) {
            free.push(i);
        }
        
        for (int i = 0; i < len; i++) {
            while (end.size() and end.top().first <= a[i][0]) {
                free.push(end.top().second);
                end.pop();
            }
            
            if ((int)end.size() == n) {
                auto val = end.top();
                end.pop();
                end.push({a[i][1] - a[i][0] + val.first, val.second});
                times[val.second]++;
            }
            else {
                time = free.top();
                free.pop();
                end.push({a[i][1], time});
                times[time]++;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (times[i] > val) {
                val = times[i];
                ans = i;
            }
        }
        
        return ans;
    }
};