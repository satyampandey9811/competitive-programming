// link to question - https://leetcode.com/problems/maximum-performance-of-a-team/

class Solution {
public:
    // very important question
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        long long int ans = 0, mod = 1e9 + 7, sum = 0;
        vector<pair<int, int>> a(n);
        for(int i = 0; i < n; i++) {
            a[i] = {e[i], s[i]};
        }
        sort(a.rbegin(), a.rend());
        priority_queue<int, vector<int>, greater<int>> q;
        
        for(int i = 0; i < n; i++) {
            q.push(a[i].second);
            sum += a[i].second;
            if(q.size() > k) {
                sum -= q.top();
                q.pop();
            }
            ans = max(ans, sum * a[i].first);
        }
        
        return ans % mod;
    }
};