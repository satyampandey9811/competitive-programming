// link to question - https://leetcode.com/problems/defuse-the-bomb/

class Solution {
public:
    vector<int> decrypt(vector<int>& a, int k) {
        
        int n = a.size();
        
        if(k == 0) {
            for(int i = 0; i < n; i++) a[i] = 0;
            return a;
        }
        
        if(k > 0) {
            vector<int> b(n);
            for(int i = 0; i < n; i++) {
                int l = i + 1;
                l %= n;
                for(int j = 1; j <= k; j++) {
                    b[i] += a[l];
                    l = (l + 1) % n;
                }
            }
            
            return b;
        }
        
        vector<int> b(n);
        k = k * (-1);
        for(int i = 0; i < n; i++) {
            int l = i - 1;
            l = (l + n) % n;
            for(int j = 1; j <= k; j++) {
                b[i] += a[l];
                l = (l - 1 + n) % n;
            }
        }   
        
        return b;
    }
};