// link to question - https://leetcode.com/problems/maximum-product-of-word-lengths/

class Solution {
public:
    int maxProduct(vector<string>& w) {
        int n = w.size(), ans = 0;
        vector<int> a(n);
        
        for(int i = 0; i < n; i++) {
            int c = 0;
            for(int j = 0; j < w[i].size(); j++) {
                c = c | (1 << (w[i][j] - 'a'));
            }
            a[i] = c;
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(!(a[i] & a[j])) 
                ans = max(ans,(int)w[i].size() * (int)w[j].size());
            }
        }
        
        return ans;
    }
};