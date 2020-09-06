// link to question - https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/

class Solution {
public:
    int numTriplets(vector<int>& a, vector<int>& b) {
        int ans = 0;
        int m = a.size(), n = b.size();
        
        map<long long int, int> s, t;
        for(int i = 0; i < m; i++) {
            for(int j = i + 1; j < m; j++) {
                s[1LL * a[i] * a[j]]++;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                t[1LL * b[i] * b[j]]++;
            }
        }
        
        for(int i = 0; i < m; i++) {
            if(t.count(1LL * a[i] * a[i])) ans += t[1LL * a[i] * a[i]];
        }
        for(int i = 0; i < n; i++) {
            if(s.count(1LL * b[i] * b[i])) ans += s[1LL * b[i] * b[i]];
        }
        
        return ans;
    }
};