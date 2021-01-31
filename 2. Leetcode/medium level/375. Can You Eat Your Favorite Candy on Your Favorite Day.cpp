// link to question - https://leetcode.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/

class Solution {
public:
    vector<bool> canEat(vector<int>& a, vector<vector<int>>& q) {
        int n = a.size();
        vector<long long> pre(n);
        pre[0] = a[0];
        for(int i = 1; i < n; i++) {
            pre[i] = a[i];
            pre[i] += pre[i-1];
        }
        
        int m = q.size();
        
        vector<bool> ans(m);
        
        long long t, d, c, can;
        for(int i = 0; i < m; i++) {
            t = q[i][0], d = q[i][1], c = q[i][2];
            can = 0;
            if(t > 0) can = pre[t-1];
            
            long long q = can / c, r = can % c;
            
            if(can + a[t] <= d) ans[i] = false;                        
            else if(q > d) ans[i] = false;
            else ans[i] = true;
        }
        
        return ans;
    }
};