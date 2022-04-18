// link to question - https://leetcode.com/problems/longest-path-with-different-adjacent-characters/

class Solution {
public:
    int ans;
    
    int go (int i, vector<vector<int>>& a, string &s) {
        int first = 0, second = 0;
        
        for (auto &j :a[i]) {
            int l = go (j, a, s);
            if (s[j] != s[i]) {
                if (l >= first) {
                    second = first;
                    first = l;
                }
                else second = max(second, l);
            }
        }
        
        ans = max(ans, first + second + 1);
        return first + 1;
    }
    
    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        ans = 0;
        vector<vector<int>> a(n);
        
        for (int i = 1; i < n; i++) {
            a[parent[i]].push_back(i);
        }
        
        go(0, a, s);
        
        return ans;
    }
};