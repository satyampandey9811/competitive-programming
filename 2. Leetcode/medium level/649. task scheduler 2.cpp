// link to question - https://leetcode.com/problems/task-scheduler-ii/

class Solution {
public:
    long long taskSchedulerII(vector<int>& a, int s) {
        long long ans = 0;
        map<int, long long> m;
        
        for (auto &i :a) {
            if (m.count(i) < 1) ans++;
            else {
                if (m[i] <= ans - s) ans++;
                else {
                    ans += s - (ans - m[i]) + 1;
                }
            }
            m[i] = ans;
        }
        
        return ans;
    }
};