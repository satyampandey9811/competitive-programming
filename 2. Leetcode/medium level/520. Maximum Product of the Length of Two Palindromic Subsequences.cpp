// link to question - https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/

class Solution {
public:
    bool check(string& a) {
        int i = 0, j = (int)a.size() - 1;
        while(i < j) {
            if(a[i] != a[j]) return 0;
            i++, j--;
        }
        return 1;
    }
    
    int maxProduct(string s) {
        int n = s.size();
        vector<array<int, 2>> b;
        
        for(int i = 0; i < (1 << n); i++) {
            int v = 0;
            string a;
            for(int j = 0; j < n; j++) {
                if(i & (1 << j)) {
                    v |= (1 << j);
                    a += s[j];
                }
            }
            if(check(a)) {
                b.push_back({v, (int)a.size()});
            }
        }
        
        int ans = 0, size = b.size();
        
        for(int i = 0; i < size; i++) {
            for(int j = i + 1; j < size; j++) {
                if(b[i][0] & b[j][0]) continue;
                ans = max(ans, b[i][1] * b[j][1]);
            }
        }
        
        return ans;
    }
};