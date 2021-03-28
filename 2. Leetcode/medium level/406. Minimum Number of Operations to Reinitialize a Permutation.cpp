// link to question - https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/

class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> a(n);
        int ans = 0;
        
        for(int i = 0; i < n; i++) a[i] = i;
        
        while(1) {
            vector<int> b(n);
            for(int i = 0; i < n; i++) {
                if(i % 2 == 0) b[i] = a[i/2];
                else b[i] = a[n/2 + (i-1)/2];
            }
            ans++;
            bool f = true;
            for(int i = 0; i < n; i++) {
                if(b[i] != i) f = false;
                a[i] = b[i];
            }
            if(f) break;
        }
        
        return ans;
    }
};