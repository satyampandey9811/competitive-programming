// link to question - https://leetcode.com/problems/count-good-meals/

class Solution {
public:
    int countPairs(vector<int>& a) {
        unordered_map<int, int> m;
        int n = a.size(), ans = 0, mod = 1e9 + 7;
        
        m[a[0]]++;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < 24; j++) {
                int x = pow(2, j) - a[i];
                if(m.count(x)) {
                    ans = (ans + m[x]) % mod;
                }
            }
            m[a[i]]++;
        }
        
        return ans;
    }
};