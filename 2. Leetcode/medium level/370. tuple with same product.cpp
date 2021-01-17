// link to question - https://leetcode.com/problems/tuple-with-same-product/

class Solution {
public:
    int tupleSameProduct(vector<int>& a) {
        map<int, int> m;
        int n = a.size(), ans = 0;
        if(n < 4) return 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                m[a[i] * a[j]]++;
            }
        }
        
        for(auto& i: m) {
            if(i.second > 1) ans += i.second * (i.second - 1) / 2;
        }
        
        return ans * 8;
    }
};