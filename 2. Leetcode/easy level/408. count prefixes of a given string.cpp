// link to question - https://leetcode.com/problems/count-prefixes-of-a-given-string/

class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int n = s.size();
        int ans = 0;
        
        for (auto &a :words) {
            int len = a.size();
            if (len <= n) {
                if (s.substr(0, len) == a) ans++;
            }
        }
        
        return ans;
    }
};