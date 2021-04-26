// link to question - https://leetcode.com/problems/furthest-building-you-can-reach/

class Solution {
public:
    int furthestBuilding(vector<int>& a, int b, int l) {
        int n = a.size(), cb = 0, cl = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        
        for(int i = 0; i < n - 1; i++) {
            if(a[i] >= a[i+1]) continue;
            if(q.size() < l) q.push(a[i+1] - a[i]);
            else {
                int val = a[i+1] - a[i];
                if(q.size() and q.top() < val) {
                    cb += q.top();
                    q.pop();
                    q.push(val);
                }
                else cb += val;
            }
            if(cb > b) return i;
        }
        
        return n - 1;
    }
};