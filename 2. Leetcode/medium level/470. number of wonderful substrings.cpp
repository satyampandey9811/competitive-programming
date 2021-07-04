// link to question - https://leetcode.com/problems/number-of-wonderful-substrings/

class Solution {
public:
    // important question
    long long wonderfulSubstrings(string a) {
        int n = a.size(), mask = 0;
        long long ans = 0;
        vector<int> m(1024);
        m[0] = 1;
        
        for(int i = 0; i < n; i++) {
            mask ^= 1 << (a[i] - 'a');
            ans += m[mask];
            
            for(int j = 0; j < 10; j++) {
                ans += m[mask ^ (1 << j)];
            }
            
            m[mask]++;
        }
        
        return ans;
    }
};