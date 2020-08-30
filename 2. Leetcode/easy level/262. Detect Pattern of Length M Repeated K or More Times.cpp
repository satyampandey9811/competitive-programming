// link to question - https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/

class Solution {
public:
    bool containsPattern(vector<int>& a, int m, int k) {
        int n = a.size();
        if(m * k > n) return 0;
        
        for(int i = 0; i <= n - m * k; i++) {
            int x = m;
            int y = k;
            bool f = true;
            
            for(int j = i; j < i + x; j++) {
                bool g = true;                
                
                for(int it = j + x; it <= j + (y - 1) * x; it += x) {
                    if(a[it] != a[j]) {
                        g = false;
                        break;
                    }
                }
                
                if(!g) {
                    f = false;
                    break;
                }
            }
            
            if(f) return 1;
        }
        
        return 0;
    }
};