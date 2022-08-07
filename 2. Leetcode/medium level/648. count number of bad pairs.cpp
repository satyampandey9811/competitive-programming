// link to question - https://leetcode.com/problems/count-number-of-bad-pairs/

class Solution {
public:
    long long countBadPairs(vector<int>& a) {
        long long ans = 0;
        map<int, long long> m;
        int n = a.size();
        
        for (int i = 0; i < n; i++) {
            m[a[i] - i]++;
        }
        
        for (auto &i :m) {
            ans += i.second * 1LL * (n - i.second);
        }
        
        return ans / 2;
    }
};