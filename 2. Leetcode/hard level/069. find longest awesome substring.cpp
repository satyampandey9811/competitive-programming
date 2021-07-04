// link to question - https://leetcode.com/problems/find-longest-awesome-substring/

class Solution {
public:
    // important question
    int longestAwesome(string s) {
        int n = s.size(), ans = 0, mask = 0;
        vector<int> m(1024, n);
        m[0] = -1;
        
        for(int i = 0; i < n; i++) {
            mask ^= 1 << (s[i] - '0');
            
            ans = max(ans, i - m[mask]);
            
            for(int j = 0; j < 10; j++) {
                ans = max(ans, i - m[mask ^ (1 << j)]);
            }
            
            m[mask] = min(m[mask], i);
        }
        
        return ans;
    }
};