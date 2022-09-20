// link to question - https://leetcode.com/problems/optimal-partition-of-string/

class Solution {
public:
    int partitionString(string s) {
        int ans = 0;
        int n = s.size();
        map<char, int> m;
        
        for (int i = 0; i < n; i++) {
            if (m.count(s[i]) > 0) {
                m.clear();
                ans++;
            }
            m[s[i]]++;
        }
        
        ans++;
        return ans;
    }
};