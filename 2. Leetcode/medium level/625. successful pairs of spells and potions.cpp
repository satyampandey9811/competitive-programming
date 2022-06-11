// link to question - https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

class Solution {
public:
    vector<int> successfulPairs(vector<int>& a, vector<int>& b, long long s) {
        sort(b.begin(), b.end());
        int n = a.size(), m = b.size();
        long long x;
        vector<int> res(n);
        
        for (int i = 0; i < n; i++) {
            x = s + a[i] - 1;
            x /= a[i];
            auto iter = lower_bound(b.begin(), b.end(), x);
            res[i] = b.end() - iter;
        }
        
        return res;
    }
};