// link to question - https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/

class Solution {
public:
    int kIncreasing(vector<int>& a, int k) {
        int n = a.size();
        int ans = 0, t;
        
        for (int i = 0; i < k; i++) {
            vector<int> b;
            t = 0;
            
            for (int j = i; j < n; j += k) {
                auto it = lower_bound(b.begin(), b.end(), a[j] + 1);
                if (it == b.end()) b.push_back(a[j]);
                else *it = a[j];
                t++;
            }
            
            ans += t - b.size();
        }
        
        return ans;
    }
};