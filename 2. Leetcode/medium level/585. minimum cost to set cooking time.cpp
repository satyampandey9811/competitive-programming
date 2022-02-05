// link to question - https://leetcode.com/problems/minimum-cost-to-set-cooking-time/

class Solution {
public: 
    int minCostSetTime (int s, int m, int p, int t) {
        int sec = t % 60;
        int minute = t / 60;
        
        if (minute > 99) minute--, sec += 60;
        
        int time = minute * 100 + sec;
        
        int ans = find (time, s, m, p);
        
        if (minute and sec <= 39) ans = min(ans, find ((minute - 1) * 100 + 60 + sec, s, m, p));
        
        return ans;
    }

    int find (int time, int s, int m, int p) {
        vector<int> a;
        int n = a.size(), ans = 0;
        
        while (time) {
            a.push_back(time % 10);
            time /= 10;
        }
        n = a.size();
        
        reverse(a.begin(), a.end());
        
        for (int i = 0; i < n; i++) {
            if (s != a[i]) {
                s = a[i];
                ans += m;
                ans += p;
            }
            else {
                ans += p;
            }
        }
        
        return ans;
    }
};