// link to question - https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/

class Solution {
public:
    int minDeletion(vector<int>& a) {
        stack<pair<int, int>> s;
        int n = a.size(), ans = 0, c = 0;
        
        for (int i = 0; i < n; i++) {
            if (s.size() and s.top().first == a[i] and s.top().second == 0) {
                ans++;
                continue;
            }
            s.push({a[i], c});
            c = !c;
        }
        
        if (s.size() % 2 == 1) ans++;
        
        return ans;
    }
};