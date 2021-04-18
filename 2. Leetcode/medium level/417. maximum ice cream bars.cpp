// link to question - https://leetcode.com/problems/maximum-ice-cream-bars/

class Solution {
public:
    int maxIceCream(vector<int>& a, int c) {
        int n = a.size(), ans = 0;
        sort(a.begin(), a.end());
        
        for(int i = 0; i < n; i++) {
            c -= a[i];
            if(c < 0) return ans;
            ans++;
        }
        
        return ans;
    }
};