// link to question - https://leetcode.com/problems/minimum-absolute-sum-difference/

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& a, vector<int>& b) {
        long long diff = 0, sum;
        int n = a.size(), mod = 1e9 + 7;
        set<int> s;
        
        for(int i = 0; i < n; i++) {
            diff += abs(a[i] - b[i]);
            s.insert(a[i]);
        }
        
        sum = diff;
        
        for(int i = 0; i < n; i++) {
            long long x = diff - abs(a[i] - b[i]);
            auto it = s.lower_bound(b[i]);
            if(it == s.end()) it--;
            sum = min(sum, x + abs(*it - b[i]));
            if(it != s.begin()) {
                it--;
                sum = min(sum, x + abs(*it - b[i]));
            }
        }
        
        return sum % mod;
    }
};