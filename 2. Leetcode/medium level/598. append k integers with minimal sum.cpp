// link to question - https://leetcode.com/problems/append-k-integers-with-minimal-sum/

class Solution {
public:
    long long minimalKSum(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int n = a.size();
        long long res = 0, totalsum;
        
        int l, f, c;
        
        c = min(k, a[0] - 1);
        k -= c;
        
        long long val = c * 1LL * (c + 1) / 2;
        res += val;
        
        if (k == 0) {
            return res;
        }
        
        for (int i = 0; i < n - 1; i++) {
            c = a[i + 1] - a[i];
            c--;
            
            if (c < 1) {
                continue;
            }
            c = min(c, k);
            k -= c;
            
            f = a[i], l = a[i] + c;
            
            totalsum = l * 1LL * (l + 1) / 2;
            totalsum -= f * 1LL * (f + 1) / 2;
            
            res += totalsum;
            if (k == 0) {
                break;
            }
        }
        
        if (k) {
            f = a[n - 1];
            l = f + k;
            
            totalsum = l * 1LL * (l + 1) / 2;
            totalsum -= f * 1LL * (f + 1) / 2;
            res += totalsum;
        }
        
        return res;
    }
};