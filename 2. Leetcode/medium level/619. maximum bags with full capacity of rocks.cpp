// link to question - https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/

class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& r, int ar) {
        int n = c.size();
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = c[i] - r[i];
        }
        
        sort(a.begin(), a.end());
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            ar -= a[i];
            if (ar < 0) break;
            ans++;
        }
        
        return ans;
    }
};