// link to question - https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/

class Solution {
public:
    long long minimumDifference(vector<int>& a) {
        int n = a.size(), rem = n / 3;
        long long ans = 0, sum = 0;
        
        priority_queue<int, vector<int>, greater<int>> q;
        vector<long long> b(n);
        
        for (int i = n - 1; i >= 2 * rem; i--) {
            sum += a[i];
            q.push(a[i]);
        }
        b[2 * rem] = sum;
        
        for (int i = 2 * rem - 1; i >= rem; i--) {
            if (a[i] > q.top()) {
                sum -= q.top();
                q.pop();
                q.push(a[i]);
                sum += a[i];
            }
            b[i] = sum;
        }
        
        priority_queue<int> p;
        sum = 0;
        
        for (int i = 0; i < rem; i++) {
            sum += a[i];
            p.push(a[i]);
        }
        
        ans = sum - b[rem];
        
        for (int i = rem; i < 2 * rem; i++) {
            if (a[i] < p.top()) {
                sum -= p.top();
                p.pop();
                p.push(a[i]);
                sum += a[i];
            }
            ans = min(ans, sum - b[i + 1]);
        }
        
        return ans;
    }
};