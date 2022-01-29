// link to question - https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int n;
    
    vector<int> findLeft (vector<int>& a) {
        vector<int> ans(n, -1);
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            while (s.size() and a[i] < a[s.top()]) {
                ans[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
    
    vector<int> findRight (vector<int>& a) {
        vector<int> ans(n, n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (s.size() and a[i] < a[s.top()]) {
                ans[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& a) {
        n = a.size();
        vector<int> left = findLeft(a);
        vector<int> right = findRight(a);
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, (right[i] - left[i] - 1) * a[i]);
        }
        return ans;
    }
};