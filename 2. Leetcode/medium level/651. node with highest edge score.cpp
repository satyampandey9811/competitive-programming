// link to question - https://leetcode.com/problems/node-with-highest-edge-score/

class Solution {
public:
    int edgeScore(vector<int>& a) {
        int n = a.size();
        long long ans = 0, val = 0;
        vector<long long> x(n);
        
        for (int i = 0; i < n; i++) {
            x[a[i]] += i;
        }
        
        for (int i = 0; i < n; i++) {
            if (x[i] > val) {
                val = x[i];
                ans = i;
            }
        }
        
        return ans;
    }
};